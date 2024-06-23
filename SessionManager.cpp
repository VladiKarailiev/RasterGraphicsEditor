#include "SessionManager.h"
#include "ImageFactory.h"
#include "ImageCommand.h"
#include "GrayscaleCommand.h"
#include "RotateCommandBase.h"
#include "RotateLeftCommand.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "RGB.h"
#include "Polymorphic_Ptr.hpp"
#include "Session.h"
#include "SessionManager.h"
#include <iostream>
#include <sstream>

Vector<Session*> SessionManager::sessions;

void SessionManager::run()
{
	int currSession = -1;
	while (true)
	{
		char buff[1024];
		std::cin.getline(buff, 1024);

		MyString input = "";

		std::stringstream ss(buff);
		ss >> input;


		if (input == "grayscale" || input == "monochrome" || input == "negative" || input == "rotate")
		{
			if (currSession == -1) continue;
			try
			{
				Polymorphic_Ptr<ImageCommand> cmd= CommandFactory::create(SessionManager::getSession(currSession)->getImages(), buff);


				getSession(currSession)->getPending().add(cmd);
			}
			catch (...)
			{
				std::cout << "Error while creating command\n";
			}
		}

		
		if (input == "add")
		{
			ss >> input;
			if (currSession == -1) continue;
			try
			{
			Image img = ImageFactory::createImage(input.c_str());

			SessionManager::getSession(currSession)->addImage(img);

			std::cout << "Image " << input << " added.\n";
			}
			catch(...)
			{
				std::cout << "Error while adding\n";
			}


		}

		if (input == "session")
		{
			ss >> input;
			if (input == "info")
			{
				if (currSession == -1) continue;
				SessionManager::getSession(currSession)->printInfo();
			}
			else
			{
				std::cout << "not a valid command\n";
			}
		}

		if (input == "switch")
		{
			int id;
			ss >> id;
			try
			{
			currSession = id;
			SessionManager::getSession(currSession)->printInfo();
			std::cout << "You switched to session with ID:" << id << "\n";
			}
			catch (...)
			{
				std::cout << "No session found with this ID.\n";
				continue;
			}


		}

		if (input == "load")
		{
			ss >> input;
			
			try {
				Image img = ImageFactory::createImage(input.c_str());

				Session* newSession = new Session(img);
				SessionManager::addSession(newSession);
				currSession = newSession->getId();
				std::cout << "Session with ID:" << newSession->getId() << " started.\n";

				}
			catch (...)
			{
				std::cout << "can't open session\n";
			}

			

		}


		if (input == "undo")
		{
			if (currSession == -1) continue;
			SessionManager::getSession(currSession)->undo();

			std::cout << "Undo executed\n";

		}

		if (input == "save")
		{
			if (currSession == -1) continue;
			SessionManager::getSession(currSession)->getPending().executeAll();
			
			for (size_t i = 0; i < getSession(currSession)->getImages().getSize(); i++)
			{
				getSession(currSession)->getImage(i).save();
			}
			///images save to files
		}

		if (input == "exit")
		{

			break;
		}

		if (input == "help")
		{
			std::cout << "HELP:\n";
			std::cout << "print - Prints out the pixels of all images in current session.\n";
			std::cout << "collage <direction> <path1> <path2> <result path> - Direction is either horizontal or vertical. Creates a collage that is saved in the result path.";
			std::cout << "exit - Ends program WITHOUT SAVING!\n";
			std::cout << "save - Saves all the files and applies all TRANSFORMATIONS in current session.\n";
			std::cout << "undo - Reverts transformations.\n";
			std::cout << "load <path> - Starts session with an image.\n";
			std::cout << "switch <id> - Switches to a different session.\n";
			std::cout << "session info - Prints out information for the current session.\n";
			std::cout << "add <path> - Adds an image to the current session.\n";
			std::cout << "grayscale/monochrome/negative - Adds transformation\n";
			std::cout << "rotate left/right - Adds rotate transformation\n";
			std::cout << "help - prints out help\n\n";
		}

		if (input == "print")
		{
			if (currSession == -1) continue;
			for (size_t i = 0; i < SessionManager::getSession(currSession)->getImages().getSize(); i++)
			{
				Image temp = SessionManager::getSession(currSession)->getImage(0);
				SessionManager::getSession(currSession)->getImage(i).print();
			}
		}

		if (input == "collage")
		{
			MyString direction,path1,path2,newpath;
			ss >> direction >> path1 >> path2 >> newpath;
			try
			{
				Image img1 = ImageFactory::createImage(path1.c_str());
				Image img2 = ImageFactory::createImage(path2.c_str());
				
				if (direction == "horizontal") ImageFactory::createHorizontalCollage(img1, img2, newpath);
				if (direction == "vertical") ImageFactory::createVerticalCollage(img1, img2, newpath);
			}
			catch (...)
			{
				std::cout << "Collage maker failed.\n";
			}
		}

	}



}

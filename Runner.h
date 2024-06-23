#pragma once
#include <iostream>
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



class Runner
{
public:
	void run() const
	{
		int id = -1;
		while (true)
		{
			std::string input;
			std::cin >> input;


			if (input == "load")
			{
				std::cin >> input;
				Image img = ImageFactory::createImage(input);
				Session session(img);
				SessionManager::addSession(&session);
				id = session.getId();
				std::cout << "Session started ID: " << id << "\n";
			}

			else if (input == "print")
			{
				if (id == -1) continue;
				SessionManager::getSession(0)->printInfo();
			}

		}
	}
};


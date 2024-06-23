#include "Session.h"
#include "CommandFactory.h"


int Session::nextId = 0;

Session::Session(Image& img) : id(nextId++) {
	images.pushBack(img);
}

Session::Session() : id(nextId++)
{

}

void Session::addImage(Image& img) {
	images.pushBack(img);
}

void Session::undo()
{
	pending.undoAll();
}

int Session::getId() const
{
	return id;
}

void Session::addTransformation(const Polymorphic_Ptr<ImageCommand>& cmd)
{
	pending.add(cmd);

}

void Session::printInfo() const
{
	std::cout << "Name of images in the session: ";
	std::cout << images.getSize() << "\n";
	
	for (size_t i = 0; i < images.getSize(); i++)
	{
		std::cout << images[i].getPath() << ' ';
	}
	std::cout << '\n' << "Pending transformations: ";
	pending.printAll();
	
}

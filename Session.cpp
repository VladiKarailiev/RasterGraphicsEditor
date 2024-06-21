#include "Session.h"
#include "CommandFactory.h"


int Session::nextId = 0;

Session::Session(Image& img)
{
	addImage(img);
	id = ++nextId;
}

int Session::getId() const
{
	return 0;
}

void Session::handleCommand()
{
	pending.add(CommandFactory::create(images));

}

void Session::addImage(Image img) // nz dali e po kopie
{
	images.pushBack(img);
}

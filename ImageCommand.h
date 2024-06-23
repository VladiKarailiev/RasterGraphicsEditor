#pragma once
#include "Command.h"
#include "Vector.hpp"
#include "Image.hpp"


class ImageCommand : public Command
{
protected:
	Vector<Image>& data;

	Vector<Image>* snapshot;
public:
	ImageCommand(Vector<Image>& data) : data(data) {}

	virtual void execute() = 0;
	void undo();

	virtual void print() const = 0;

	virtual ~ImageCommand() = default;
	virtual ImageCommand* clone() const = 0;

};


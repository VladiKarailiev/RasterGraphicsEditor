#pragma once
#include "Vector.hpp"
#include "Image.hpp"


class ImageCommand
{
protected:
	Image& data;

	Image* snapshot;
public:
	ImageCommand(Image& data) : data(data) {}

	virtual void execute() = 0;
	void undo();

	virtual ~ImageCommand() = default;
	virtual ImageCommand* clone() const = 0;

};


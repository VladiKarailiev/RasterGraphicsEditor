#pragma once
#include "Vector.hpp"
#include "Image.hpp"


class ImageCommand 
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


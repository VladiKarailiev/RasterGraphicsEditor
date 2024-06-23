#pragma once
#include "ImageCommand.h"
class RotateLeftCommand :
	public ImageCommand
{

public:
	RotateLeftCommand(Vector<Image>& data);
	void execute() override;

	void print() const override;
	ImageCommand* clone() const override;
};


// za preimenuvane e !
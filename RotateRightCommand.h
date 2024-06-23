#pragma once
#include "ImageCommand.h"
class RotateRightCommand :
	public ImageCommand
{

public:
	RotateRightCommand(Vector<Image>& data);
	void execute() override;
	void print() const override;
	ImageCommand* clone() const override;
};


// za preimenuvane e !
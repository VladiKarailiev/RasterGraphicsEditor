#pragma once
#include "ImageCommand.h"
class RotateRightCommand :
	public ImageCommand
{

public:
	RotateRightCommand(Image& data);
	void execute() override;

	ImageCommand* clone() const override;
};


// za preimenuvane e !
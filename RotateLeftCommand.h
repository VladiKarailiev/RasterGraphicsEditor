#pragma once
#include "ImageCommand.h"
class RotateLeftCommand :
	public ImageCommand
{

public:
	RotateLeftCommand(Image& data);
	void execute() override;

	ImageCommand* clone() const override;
};


// za preimenuvane e !
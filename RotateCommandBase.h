#pragma once
#include "ImageCommand.h"
class RotateCommandBase :
	public ImageCommand
{
	
public:
	RotateCommandBase(Image& data);
	void execute() override;

	ImageCommand* clone() const override;
};


// za preimenuvane e !
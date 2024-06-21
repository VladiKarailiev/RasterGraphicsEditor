#pragma once
#include "ImageCommand.h"
class NegativeCommand :
	public ImageCommand
{
public:
	NegativeCommand(Image& data);
	void execute() override;


	ImageCommand* clone() const override;
};


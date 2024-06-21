#pragma once
#include "ImageCommand.h"
class MonochromeCommand :
	public ImageCommand
{

public:
	MonochromeCommand(Image& data);
	void execute() override;


	ImageCommand* clone() const override;
};


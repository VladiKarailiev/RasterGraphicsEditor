#pragma once
#include "ImageCommand.h"
class MonochromeCommand :
	public ImageCommand
{

public:
	MonochromeCommand(Vector<Image>& data);
	void execute() override;


	ImageCommand* clone() const override;
};


#pragma once
#include "ImageCommand.h"
class GrayscaleCommand :
    public ImageCommand
{

public:
	GrayscaleCommand(Image& data);
	void execute() override;


	ImageCommand* clone() const override;
};


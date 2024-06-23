#pragma once
#include "ImageCommand.h"
class GrayscaleCommand :
    public ImageCommand
{

public:
	GrayscaleCommand(Vector<Image>& data);
	void execute() override;

	void print() const override;
	ImageCommand* clone() const override;
};


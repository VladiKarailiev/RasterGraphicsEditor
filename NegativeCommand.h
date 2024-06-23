#pragma once
#include "ImageCommand.h"
class NegativeCommand :
	public ImageCommand
{
public:
	NegativeCommand(Vector<Image>& data);
	void execute() override;


	void print() const override;
	ImageCommand* clone() const override;
};


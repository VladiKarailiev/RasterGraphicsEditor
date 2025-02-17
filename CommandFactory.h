#pragma once
#include "Polymorphic_Ptr.hpp"
#include "ImageCommand.h"
#include "GrayscaleCommand.h"
#include "MonochromeCommand.h"
#include "NegativeCommand.h"
#include "RotateLeftCommand.h"
#include "RotateRightCommand.h"
#include <sstream>
#include "MyString.h"


class CommandFactory {
public:

	static Polymorphic_Ptr<ImageCommand> create(Vector<Image>& data,MyString input) {
		std::stringstream ss(input.c_str());

		MyString cmd;
		ss >> cmd;
		if (cmd == "grayscale") {

			return new GrayscaleCommand(data);

		}
		else if (cmd == "monochrome") {
			return new MonochromeCommand(data);
		}
		else if (cmd == "negative") {
			return new NegativeCommand(data);
		}
		else if (cmd == "rotate") {
			ss >> cmd;
			if (cmd == "left")
				return new RotateLeftCommand(data);
			else if (cmd == "right")
				return new RotateRightCommand(data);
			else throw std::invalid_argument("Invalid rotate direction");
		}


		throw std::invalid_argument("Invalid command");
	}
};
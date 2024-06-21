#pragma once
#include "ImageCommand.h"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Polymorphic_Ptr.hpp"
#include "GrayscaleCommand.h"
#include "MonochromeCommand.h"
#include "NegativeCommand.h"
#include "RotateLeftCommand.h"
#include "RotateRightCommand.h"

class CommandExecutor
{
	MyQueue< Polymorphic_Ptr<ImageCommand>> toBeExecuted;
	MyStack< Polymorphic_Ptr<ImageCommand>, 64> history;

	CommandExecutor() = default;
	~CommandExecutor() = default;
public:
	void add(ImageCommand* c);

	void execute();
	void executeAll();

	void undo();

	static CommandExecutor& getInstance() {
		static CommandExecutor executor;
		return executor;
	}

	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
};

class Factory {
public:

	static Polymorphic_Ptr<ImageCommand> create(Image& data) {
		std::string cmd;
		std::cin >> cmd;
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
			std::cin >> cmd;
			if (cmd == "left")
				return new RotateLeftCommand(data);
			else if (cmd == "right")
				return new RotateRightCommand(data);
			else throw std::invalid_argument("Invalid rotate direction");
		}


		throw std::invalid_argument("Invalid command number");
	}
};
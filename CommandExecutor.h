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

public:

	CommandExecutor() = default;
	~CommandExecutor() = default;
	void add(ImageCommand* c);
	void add(Polymorphic_Ptr<ImageCommand> c);

	void execute();
	void executeAll();

	void printAll() const;

	void undo();
	void undoAll();

	/*static CommandExecutor& getInstance() {
		static CommandExecutor executor;
		return executor;
	}*/

};

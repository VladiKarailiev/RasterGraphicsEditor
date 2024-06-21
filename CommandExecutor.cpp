#include "CommandExecutor.h"

void CommandExecutor::add(ImageCommand* c)
{
	toBeExecuted.push(c);
}

void CommandExecutor::add(Polymorphic_Ptr<ImageCommand> c)
{
	toBeExecuted.push(c);
}

void CommandExecutor::execute()
{
	if (!toBeExecuted.isEmpty()) {
		Polymorphic_Ptr<ImageCommand> temp = toBeExecuted.peek();
		temp->execute();
		toBeExecuted.pop();

		history.push(temp);
	}
}

void CommandExecutor::executeAll()
{
	while (!toBeExecuted.isEmpty()) {
		execute();
	}
}

void CommandExecutor::undo()
{
	if (!history.isEmpty()) {
		Polymorphic_Ptr<ImageCommand> temp = history.peek();
		temp->undo();

		history.pop();
	}
}
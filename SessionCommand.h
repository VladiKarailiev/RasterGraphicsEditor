#pragma once
#include "Vector.hpp"
#include "Session.h"
#include "Command.h"


class SessionCommand : public Command
{
protected:
	Session& data;
public:
	SessionCommand(Session& data) : data(data) {}

	virtual void execute() = 0;
	
	virtual ~SessionCommand() = default;
	virtual SessionCommand* clone() const = 0;

};


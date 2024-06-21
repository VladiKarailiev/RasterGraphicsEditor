#pragma once
#include "Vector.hpp"
#include "Session.h"


class SessionCommand
{
protected:
	Session& data;
public:
	SessionCommand(Session& data) : data(data) {}

	virtual void execute() = 0;
	void undo();

	virtual ~SessionCommand() = default;
	virtual SessionCommand* clone() const = 0;

};


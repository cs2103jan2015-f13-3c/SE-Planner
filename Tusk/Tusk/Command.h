#pragma once

enum CommandType {
	Create, Read, Update, Delete
};

class Command {
private:
	CommandType _commandType;

public:
	Command(CommandType);
	~Command(void);
	CommandType getCommandType();
};
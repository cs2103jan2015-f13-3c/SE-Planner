#pragma once

enum CommandType {
	Create, Read, Update, Delete
};

class Command {
private:
	CommandType _commandType;

public:
	Command(void);
	~Command(void);

	void inputCommandType(CommandType);

	CommandType getCommandType();
};
#pragma once

enum CommandType {
	CREATE, READ, UPDATE, DELETE
};

class Command {
private:
	CommandType _commandType;

public:
	Command(void);
	~Command(void);

	void setCommandType(CommandType);
	CommandType getCommandType();
};
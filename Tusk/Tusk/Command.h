#pragma once

enum CommandType {
	Create, Read, Update, Delete
};

class Command {
private:
	CommandType _type;

public:
	Command(void);
	~Command(void);

	void inputType(CommandType);
	CommandType getType();
};
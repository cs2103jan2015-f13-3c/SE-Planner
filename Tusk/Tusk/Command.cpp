#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::inputType(CommandType type) {
	_type = type;
}

CommandType Command::getType() {
	return _type;
}
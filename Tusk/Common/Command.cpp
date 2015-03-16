#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::setCommandType(CommandType commandType) {
	_commandType = commandType;
}

void Command::setIndex(int index) {
	_index = index;
}

CommandType Command::getCommandType() {
	return _commandType;
}

int Command::getIndx() {
	return _index;
}
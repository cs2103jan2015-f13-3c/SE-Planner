#include "CommandExecutor.h"

CommandExecutor::CommandExecutor(void) {
}

CommandExecutor::~CommandExecutor(void) {
}

std::vector<Task> CommandExecutor::executeCommand(Command command) {
	std::vector<Task> result;
	result = command.execute();
	return result;
}
#include <sstream>
#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::run() {
	std::string userInput = inputUserCommand();
	CommandType commandType = _logic.executeUserInput(userInput);
	while (commandType != EXIT) {
		printResult(commandType, _logic.getResult());
		userInput = inputUserCommand();
		commandType = _logic.executeUserInput(userInput);
	}
}

std::string UI::inputUserCommand() {
	std::string userCommand;
	getline(cin, userCommand);
	return userCommand;
}

void UI::printResult(CommandType commandType, std::vector<Task> result) {
	switch (commandType) {
	case ADD:
		std::cout << "Added: " << taskToString(result[0]) << endl;
		break;
	case REMOVE:
		std::cout << "Deleted: " << taskToString(result[0]) << endl;
		break;
	case EDIT:
		std::cout << "Edited: " << taskToString(result[0]) << endl;
		break;
	case DISPLAY:
		std::cout << "Display:\n" << vectorTaskToString(result) << endl;
		break;
	case SEARCH:
		std::cout << "Search:\n" << vectorTaskToString(result) << endl;
		break;
	case MARK:
		std::cout << "Edited: " << taskToString(result[0]) << endl;
		break;
	case UNDO:
		std::cout << "Undo last action" << endl;
		break;
	case ERROR:
		std::cout << "ERROR ENCOUNTERED" << endl;
		break;
	};
}

std::string UI::taskToString(Task task) {
	ostringstream oss;

	oss << task.getDescription();

	if (task.getTaskType() != FLOATINGTASK) {
		oss << ", " 
			<< task.getStartingDate().getDay() << "/"
			<<  task.getStartingDate().getMonth() << "/"
			<<  task.getStartingDate().getYear() << "-"

			<< task.getEndingDate().getDay() << "/"
			<< task.getEndingDate().getMonth() << "/"
			<< task.getEndingDate().getYear() << ", "

			<< task.getStartingTime().getHours() << ":"
			<< task.getStartingTime().getMinutes() << "-"

			<< task.getEndingTime().getHours() << ":"
			<< task.getEndingTime().getMinutes();
	}

	if (task.getIsDone()) {
		oss << "\tDONE" << endl;
	} else {
		oss << "\tNOT DONE" << endl;
	}

	return oss.str();
}

std::string UI::vectorTaskToString(std::vector<Task> vectorTask) {
	ostringstream oss;

	for (int i = 0; i < vectorTask.size(); i++) {
		oss << i << ". " << taskToString(vectorTask[i]);
	}

	return oss.str();
}
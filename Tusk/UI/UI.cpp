#include "windows.h"
#include "UI.h"

//#include "easylogging++.h"

//INITIALIZE_EASYLOGGINGPP

/*
double PCFreq = 0.0;
__int64 CounterStart = 0;

void UI::startCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double UI::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
*/

UI::UI(void) {
	_logic = new Logic;
}

UI::~UI(void) {
}

void UI::run() {
	std::string input = inputUserCommand();
	CommandType commandType = _logic->executeUserInput(input);
	while (commandType != EXIT_CMD) {
		printResult(_logic->getResult(), commandType);
		input = inputUserCommand();
		commandType = _logic->executeUserInput(input);
	}


		/*
		double operationTime = getCounter();

		LOG(INFO) << "COMMAND: ";
		LOG(INFO) << userCommand;
		LOG(INFO) << operationTime;
		*/
}

std::string UI::inputUserCommand() {
	string input = "";
	getline(std::cin, input);
	return input;
}

void UI::printResult(const vector<Task> vectorTask, const CommandType commandType){
	switch(commandType) {
	case ADD_CMD:
		cout << SUCCESS_ADD << endl << endl;
		break;
	case DELETE_CMD:
		cout << SUCCESS_DELETE << endl << endl;
		break;
	case DISPLAY_CMD:
		vectorToString(vectorTask);
		break;
	case EDIT_CMD:
		cout << SUCCESS_EDIT << endl << endl;
		break;
	case SEARCH_CMD:
		vectorToString(vectorTask);
		break;
	case EXIT_CMD:
		cout << SUCCESS_EXIT << endl << endl;
	default:
		cout << ERROR_GENERAL << endl << endl;
		break;
	}
}

void UI::vectorToString(vector<Task> vectorTask) {
	ostringstream oss;
	vector<Task>::iterator iter;

	int i = 1;
	for (iter = vectorTask.begin(); iter != vectorTask.end(); iter++, i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << i << ". ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << iter->getTitle();

		if (iter->getTaskType() == TIMEDTASK || iter->getTaskType() == DEADLINE) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << ", ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << iter->getStartingDate().getDay() << "/";
			cout << iter->getStartingDate().getMonth() << "/";
			cout << iter->getStartingDate().getYear();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << " [" << iter->getStartingTime().getHours() << ":";
			cout << iter->getStartingTime().getMinutes() << "]";
		}
		if (iter->getTaskType() == TIMEDTASK) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << iter->getEndingDate().getDay() << "/";
			cout << iter->getEndingDate().getMonth() << "/";
			cout << iter->getEndingDate().getYear();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << " [" << iter->getEndingTime().getHours() << ":";
			cout << iter->getEndingTime().getMinutes() << "]";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		iter->getIsDone() ? oss << " DONE" : oss << " NOT DONE";
		cout << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
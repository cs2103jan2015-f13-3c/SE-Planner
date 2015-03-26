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
	while (commandType != EXIT) {
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
	case ADD:
		cout << SUCCESS_ADD << endl << endl;
		break;
	case DELETE;
		cout << SUCCESS_DELETE << endl << endl;
		break;
	case DISPLAY:
		cout << vectorToString(vectorTask);
		break;
	case EDIT:
		cout << SUCCESS_EDIT << endl << endl;
		break;
	case SEARCH:
		cout << vectorToString(vectorTask);
		break;
	case EXIT:
		cout << SUCCESS_EXIT << endl << endl;
	default:
		cout << ERROR_GENERAL << endl << endl;
		break;
	}
}

string UI::vectorToString(vector<Task> vectorTask) {
	ostringstream oss;
	vector<Task>::iterator iter;

	int i = 1;
	for (iter = vectorTask.begin(); iter != vectorTask.end(); iter++, i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		oss << i << ". ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		oss << iter->getTitle();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		oss << ", ";

		if (iter->getTaskType() == TIMEDTASK || iter->getTaskType == DEADLINE) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			oss << iter->getStartingDate.getDay() << "/";
			oss << iter->getStartingDate.getMonth() << "/";
			oss << iter->getStartingDate.getYear();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			oss << " [" << iter->getStartingTime.getHours() << ":";
			oss << iter->getStartingTime.getMinutes() << "]";
		}
		if (iter->getTaskType() == TIMEDTASK) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			oss << " - ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			oss << iter->getEndingDate.getDay() << "/";
			oss << iter->getEndingDate.getMonth() << "/";
			oss << iter->getEndingDate.getYear();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			oss << " [" << iter->getEndingTime.getHours() << ":";
			oss << iter->getEndingTime.getMinutes() << "]";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		iter->getIsDone() ? oss << " DONE" : oss << " NOT DONE";
		oss << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	return oss.str();
}
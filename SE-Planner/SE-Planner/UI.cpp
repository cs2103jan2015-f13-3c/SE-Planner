//@author A0115935A
#include "UI.h"
#include "Utility.h"

#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

UI::UI(void) {
	_outputString = "";
}


UI::~UI(void) {
}

string UI::getInput(void) {
	cout << COMMAND_PROMPT_ARROW;
	string input;
	getline(cin,input);
	return input;
}

void UI::showSuccessMessage(void) {
	showMessage(SUCCESS_EXECUTE_COMMAND);
}

void UI::showFailureMessage(void) {
	showMessage(ERROR_INVALID_COMMAND);
}

void UI::showExitMessage(void) {
	showMessage(SUCCESS_EXIT);
}

void UI::showMessage(string message) {
	_outputString = message + "\n";
	cout << message << endl;
}

bool UI::printIfEmpty(const vector<Task> showArray) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (showArray.size() == 0) {
		SetConsoleTextAttribute(hConsole,YELLOW);
		showMessage(ERROR_VECTOR_EMPTY);
		SetConsoleTextAttribute(hConsole,LIGHT_GREY);
		return true;
	}

	return false;
}

void UI::getMaxTitleAndInfoLength(const vector<Task> showArray, int &maxTitleLength, int &maxInfoLength) {
	for (int i = 0; i < (int) showArray.size(); i++) {
		maxTitleLength = max(maxTitleLength, (int) showArray[i].title.length());

		if (showArray[i].taskType == DEAD) {
			string infoString = "";
			infoString = infoString + to_string(showArray[i].startDate.day) + DATE_DELIMITER + to_string(showArray[i].startDate.month) + DATE_DELIMITER + to_string(showArray[i].startDate.year) + " ";
			infoString += LEFT_BRACE;
			infoString = infoString + to_string(showArray[i].startTime.hour) + TIME_DELIMITER;
			if (showArray[i].startTime.min < 10) {
				infoString += '0'; // 08:0 -> 08:00, aesthetic purpose
			}
			infoString += to_string(showArray[i].startTime.min);
			infoString += RIGHT_BRACE;
			maxInfoLength = max(maxInfoLength, (int) infoString.length());
		}

		if (showArray[i].taskType == TIMED) {
			string infoString = "";
			infoString = infoString + to_string(showArray[i].startDate.day) + DATE_DELIMITER + to_string(showArray[i].startDate.month) + DATE_DELIMITER + to_string(showArray[i].startDate.year)+" ";
			infoString += LEFT_BRACE;
			infoString = infoString + to_string(showArray[i].startTime.hour) + TIME_DELIMITER;
			
			if (showArray[i].startTime.min < 10) {
				infoString += '0';
			}
			infoString += to_string(showArray[i].startTime.min);
			infoString += RIGHT_BRACE;
			
			infoString += DASH;

			infoString = infoString + to_string(showArray[i].endDate.day) + DATE_DELIMITER + to_string(showArray[i].endDate.month) + DATE_DELIMITER + to_string(showArray[i].endDate.year) + " ";
			infoString += LEFT_BRACE;
			infoString = infoString + to_string(showArray[i].endTime.hour) + TIME_DELIMITER;
			
			if (showArray[i].endTime.min < 10) {
				infoString += '0';
			}
			infoString += to_string(showArray[i].endTime.min);
			infoString += RIGHT_BRACE;
			maxInfoLength = max(maxInfoLength, (int) infoString.length());
			//cout<<infoString.length()<<endl;
		}
		//cout<<maxTitleLength<<" "<<maxInfoLength<<endl;

	}
}

void UI::printUpperBorder(const int maxTitleLength, const int maxInfoLength) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

	SetConsoleTextAttribute(hConsole, WHITE);
	cout << border[CORNER_UL];
	for (int i = 2; i <= 5; i++) {
		cout << border[HORIZONTAL];
	}
	cout<<border[UPPER_CENTER];
	for (int i = 7; i <= maxTitleLength + 8; i++) {
		cout << border[HORIZONTAL];
	}
	cout << border[UPPER_CENTER];
	for (int i = maxTitleLength + 9; i <= maxInfoLength + maxTitleLength + 10; i++) {
		cout << border[HORIZONTAL];
	}
	cout << border[CORNER_UR] << endl;
}

void UI::printMainContent(const vector<Task> showArray, const int maxTitleLength, const int maxInfoLength) {
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	for (int i = 0; i < (int) showArray.size(); i++) {
		cout << border[VERTICAL] << " ";
		cout << to_string(i + 1) + ".";
		if (i + 1 < 10) {
			cout << " ";
		}
		cout << border[VERTICAL] << " ";
		SetConsoleTextAttribute(hConsole, GREEN);
		cout << showArray[i].title;
		SetConsoleTextAttribute(hConsole, WHITE);

		for (int j = 1; j <= maxTitleLength - (int) showArray[i].title.length(); j++) {
			cout << " ";
		}
		cout << " ";

		cout << border[VERTICAL] << " ";
		string infoString = "";

		if (showArray[i].taskType == DEAD) {
			SetConsoleTextAttribute(hConsole, YELLOW);
			string dateString = to_string(showArray[i].startDate.day) + DATE_DELIMITER + to_string(showArray[i].startDate.month) + DATE_DELIMITER + to_string(showArray[i].startDate.year) + " ";
			cout << dateString;
			infoString = infoString + dateString;

			string timeString = LEFT_BRACE + to_string(showArray[i].startTime.hour) + ":";

			if (showArray[i].startTime.min < 10) {
				timeString += '0';
			}
			timeString += to_string(showArray[i].startTime.min);
			timeString += RIGHT_BRACE;
			SetConsoleTextAttribute(hConsole, TURQOISE);
			cout << timeString;

			infoString = infoString + timeString;
		} else if (showArray[i].taskType == TIMED) {
			SetConsoleTextAttribute(hConsole, YELLOW);
			string dateString = to_string(showArray[i].startDate.day) + DATE_DELIMITER + to_string(showArray[i].startDate.month) + DATE_DELIMITER + to_string(showArray[i].startDate.year) + " ";
			cout << dateString;
			infoString = infoString + dateString;

			string timeString = LEFT_BRACE + to_string(showArray[i].startTime.hour) + TIME_DELIMITER;

			if (showArray[i].startTime.min < 10) {
				timeString += '0';
			}
			timeString += to_string(showArray[i].startTime.min);
			timeString += RIGHT_BRACE;
			SetConsoleTextAttribute(hConsole, TURQOISE);
			cout << timeString;

			infoString = infoString + timeString;

			SetConsoleTextAttribute(hConsole, WHITE);
			cout << DASH;
			infoString += DASH;

			SetConsoleTextAttribute(hConsole, YELLOW);
			dateString = to_string(showArray[i].endDate.day) + DATE_DELIMITER + to_string(showArray[i].endDate.month) + DATE_DELIMITER + to_string(showArray[i].endDate.year) + " ";
			cout << dateString;
			infoString = infoString + dateString;

			timeString = LEFT_BRACE + to_string(showArray[i].endTime.hour) + TIME_DELIMITER;

			if (showArray[i].endTime.min < 10) {
				timeString += '0';
			}

			timeString += to_string(showArray[i].endTime.min);
			timeString += RIGHT_BRACE;
			SetConsoleTextAttribute(hConsole, TURQOISE);
			cout << timeString;

			infoString = infoString + timeString;
			//cout<<infoString<<" "<<infoString.length()<<endl;
		}

		SetConsoleTextAttribute(hConsole, WHITE);
		for (int j = 1; j < maxInfoLength - (int) infoString.length() + 1; j++) {
			cout << " ";
		}
		cout << " ";
		cout << border[VERTICAL];

		//cout<<infoString.length()<<" "<<maxInfoLength<<endl;
		cout << endl;
	}
}
void UI::printLowerBorder(const int maxTitleLength, const int maxInfoLength) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << border[CORNER_BL];
	for (int i = 2; i <= 5; i++) cout<<border[HORIZONTAL];
	cout<<border[LOWER_CENTER];
	for (int i = 7; i <= maxTitleLength + 8; i++) cout<<border[HORIZONTAL];
	cout<<border[LOWER_CENTER];
	for (int i = maxTitleLength + 9; i <= maxInfoLength + maxTitleLength + 10; i++) cout<<border[HORIZONTAL];
	cout<<border[CORNER_BR]<<endl;
	cout<<"\n";
}

void UI::showTaskList(vector<Task> showArray) {
	int maxTitleLength = 0;
	int maxInfoLength = 0;
	
	// color variable
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

	// Nothing to Show
	if (printIfEmpty(showArray)) {
		return;
	}

	// GET THE WIDTH OF TABLE
	getMaxTitleAndInfoLength(showArray, maxTitleLength, maxInfoLength);
	
	// output upper border
	printUpperBorder(maxTitleLength, maxInfoLength);
	
	// output main content
	printMainContent(showArray, maxTitleLength, maxInfoLength);

	// output lower border
	printLowerBorder(maxTitleLength, maxInfoLength);
	
}

void UI::showHelp() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int helpColours[NUM_HELP_FIELDS] = {WHITE, YELLOW, GREEN, TURQOISE, PINK};
	
	showMessage("\n");
	
	for (int i = 0; i < NUM_COMMANDS; i++) {
		for (int j = 0; j < NUM_HELP_FIELDS; j++) {
			SetConsoleTextAttribute(hConsole, helpColours[j]);
			cout << helpStringArray[i][j];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, LIGHT_GREY);
	showMessage("\n");
}

//TESTING METHOD

string UI::getOutputString() {
	return _outputString;
}

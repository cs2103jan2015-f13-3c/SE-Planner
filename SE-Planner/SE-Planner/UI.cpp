#include "UI.h"
#include "Utility.h"

#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

UI::UI(void)
{
}


UI::~UI(void)
{
}

string UI::getInput(void)
{
	cout<<"> ";
	string input;
	getline(cin,input);
	return input;
}

void UI::showSuccessMessage(void)
{
	cout<<"Command Successfully Executed\n";
}

void UI::showFailureMessage(void)
{
	cout<<"Invalid Command. Please enter again\n\n";
}

void UI::showExitMessage(void)
{
	cout<<"Bye bye\n";
}

void UI::showMessage(string x)
{
	cout<<x<<endl;
}


void UI::showTaskList(vector<Task> showArray)
{
	// color variable
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

	// Nothing to Show
	if (showArray.size() == 0)
	{
		SetConsoleTextAttribute(hConsole,14);
		cout<<"Empty"<<endl<<endl;
		SetConsoleTextAttribute(hConsole,7);
		return;
	}

	// GET THE WIDTH OF TABLE
	int maxTitleLength = 0;
	int maxInfoLength = 0;

	for (int i = 0; i < showArray.size(); i++)
	{
		maxTitleLength = max(maxTitleLength,showArray[i].title.length());

		if (showArray[i].taskType == DEAD)
		{
			string infoString = "";
			infoString = infoString + to_string(showArray[i].startDate.day)+"/"+to_string(showArray[i].startDate.month)+"/"+to_string(showArray[i].startDate.year)+" ";
			infoString += '[';
			infoString = infoString + to_string(showArray[i].startTime.hour) + ":";
			if (showArray[i].startTime.min < 10) infoString += '0'; // 08:0 -> 08:00, aesthetic purpose
			infoString += to_string(showArray[i].startTime.min);
			infoString += ']';
			maxInfoLength = max(maxInfoLength,infoString.length());
		}

		if (showArray[i].taskType == TIMED)
		{
			string infoString = "";
			infoString = infoString + to_string(showArray[i].startDate.day)+"/"+to_string(showArray[i].startDate.month)+"/"+to_string(showArray[i].startDate.year)+" ";
			infoString += '[';
			infoString = infoString + to_string(showArray[i].startTime.hour) + ":";
			if (showArray[i].startTime.min < 10) infoString += '0';
			infoString += to_string(showArray[i].startTime.min);
			infoString += ']';
			
			infoString += " - ";

			infoString = infoString + to_string(showArray[i].endDate.day)+"/"+to_string(showArray[i].endDate.month)+"/"+to_string(showArray[i].endDate.year)+" ";
			infoString += '[';
			infoString = infoString + to_string(showArray[i].endTime.hour) + ":";
			if (showArray[i].endTime.min < 10) infoString += '0';
			infoString += to_string(showArray[i].endTime.min);
			infoString += ']';
			maxInfoLength = max(maxInfoLength,infoString.length());
			//cout<<infoString.length()<<endl;
		}

	}

	//cout<<maxTitleLength<<" "<<maxInfoLength<<endl;
	
	// output upper border
	SetConsoleTextAttribute(hConsole,15);
	cout << border[CORNER_UL];
	for (int i = 2; i <= 5; i++) cout<<border[HORIZONTAL];
	cout<<border[UPPER_CENTER];
	for (int i = 7; i <= maxTitleLength + 8; i++) cout<<border[HORIZONTAL];
	cout<<border[UPPER_CENTER];
	for (int i = maxTitleLength + 9; i <= maxInfoLength + maxTitleLength + 10; i++) cout<<border[HORIZONTAL];
	cout<<border[CORNER_UR]<<endl;

	// output main content
	for (int i = 0; i < showArray.size(); i++)
	{
		cout<<border[VERTICAL]<< " ";
		cout<<to_string(i+1)+".";
		if (i + 1 < 10) cout<<" ";

		cout<<border[VERTICAL]<< " ";
		SetConsoleTextAttribute(hConsole,10);
		cout<<showArray[i].title;
		SetConsoleTextAttribute(hConsole,15);
		for (int j = 1; j <= maxTitleLength - showArray[i].title.length(); j++) cout<<" ";
		cout<<" ";

		cout<<border[VERTICAL]<< " ";
		string infoString = "";
		if (showArray[i].taskType == DEAD)
		{
			SetConsoleTextAttribute(hConsole,14);
			string dateString = to_string(showArray[i].startDate.day)+"/"+to_string(showArray[i].startDate.month)+"/"+to_string(showArray[i].startDate.year)+" ";
			cout<<dateString;
			infoString = infoString + dateString;

			string timeString = '[' + to_string(showArray[i].startTime.hour) + ":";
			if (showArray[i].startTime.min < 10) timeString += '0';
			timeString += to_string(showArray[i].startTime.min);
			timeString += ']';
			SetConsoleTextAttribute(hConsole,11);
			cout<<timeString;

			infoString = infoString + timeString;
		}

		if (showArray[i].taskType == TIMED)
		{
			SetConsoleTextAttribute(hConsole,14);
			string dateString = to_string(showArray[i].startDate.day)+"/"+to_string(showArray[i].startDate.month)+"/"+to_string(showArray[i].startDate.year)+" ";
			cout<<dateString;
			infoString = infoString + dateString;

			string timeString = '[' + to_string(showArray[i].startTime.hour) + ":";
			if (showArray[i].startTime.min < 10) timeString += '0';
			timeString += to_string(showArray[i].startTime.min);
			timeString += ']';
			SetConsoleTextAttribute(hConsole,11);
			cout<<timeString;

			infoString = infoString + timeString;

			SetConsoleTextAttribute(hConsole,15);
			cout<<" - ";
			infoString += " - ";

			SetConsoleTextAttribute(hConsole,14);
			dateString = to_string(showArray[i].endDate.day)+"/"+to_string(showArray[i].endDate.month)+"/"+to_string(showArray[i].endDate.year)+" ";
			cout<<dateString;
			infoString = infoString + dateString;

			timeString = '[' + to_string(showArray[i].endTime.hour) + ":";
			if (showArray[i].endTime.min < 10) timeString += '0';
			timeString += to_string(showArray[i].endTime.min);
			timeString += ']';
			SetConsoleTextAttribute(hConsole,11);
			cout<<timeString;

			infoString = infoString + timeString;
			//cout<<infoString<<" "<<infoString.length()<<endl;
			
		}
		
		SetConsoleTextAttribute(hConsole,15);
		for (int j = 1; j < maxInfoLength - infoString.length() + 1; j++) cout<<" ";
		cout<<" ";
		cout<<border[VERTICAL];
		

		//cout<<infoString.length()<<" "<<maxInfoLength<<endl;
		cout<<endl;


	}


	// output lower border
	SetConsoleTextAttribute(hConsole,15);
	cout<<border[CORNER_BL];
	for (int i = 2; i <= 5; i++) cout<<border[HORIZONTAL];
	cout<<border[LOWER_CENTER];
	for (int i = 7; i <= maxTitleLength + 8; i++) cout<<border[HORIZONTAL];
	cout<<border[LOWER_CENTER];
	for (int i = maxTitleLength + 9; i <= maxInfoLength + maxTitleLength + 10; i++) cout<<border[HORIZONTAL];
	cout<<border[CORNER_BR]<<endl;
	cout<<"\n";
}

void UI::showHelp()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole,11);
	showMessage("\n");
	showMessage("add\t [title] \tdate: DD/MM/YY - DD/MM/YY \ttime: HHMM - HHMM\n");
	showMessage("search\t [title] \tdate: DD/MM/YY - DD/MM/YY \ttime: HHMM - HHMM\n");
	showMessage("delete\t [index]\n");
	showMessage("done\t [index]\n");
	showMessage("edit\t [index] [title] \tdate: [new date] \ttime: [new time]\n");
	showMessage("display\t [today, tomorrow, overdue, all, DD/MM/YY]\n");
	showMessage("undo\n");
	showMessage("cls\n");
	SetConsoleTextAttribute(hConsole,7);
}


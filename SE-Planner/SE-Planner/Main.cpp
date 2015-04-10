#include "Parser.h"
#include "UI.h"
#include "Storage.h"
#include "Logic.h"
#include "History.h"

#include <iostream>
#include <regex>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	//cout<<"Hello"<<endl;

	/*
	while (true) {
	string inp;
	getline(cin,inp);
	cout<<"INP = "<<inp<<endl;
	regex rgx("date:\\s*([\\d\\/]+\\s*-\\s*[\\d\\/]+)");
	smatch result;
	regex_search(inp, result, rgx);
	for(size_t i=0; i<result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	

	// v0.2 Parser TEST
	Parser test;
	while (true)
	{
		string cmd;
		getline(cin,cmd);

		test = Parser(cmd);

	}
	// end of PARSER TEST
	*/

	// TEST ADD, DEL, EXIT, INPUT, OUTPUT
	vector<Task> MainTaskList;
	vector<Task> DisplayTaskList;

	MainTaskList.clear();
	DisplayTaskList.clear();

	UI ui;
	Storage storage = Storage("output.txt");
	Parser parser;
	Logic logic;
	History history;
	
	bool isDifferentState = true;

	while (true)
	{
		MainTaskList = storage.getAllTask();

		if (isDifferentState) history.push(MainTaskList);

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,15);
		string userString = ui.getInput();
		//SetConsoleTextAttribute(hConsole,15);

		parser = Parser(userString);

		Command userCommand = parser.getCommand();
		Task userTask = parser.getTask();

		// LOGIC PART
		// CAN BE SEPARATED LATER
		//SetConsoleTextAttribute(hConsole,11);

		if (userCommand.cmd == INVALID)
		{
			ui.showMessage("WRONG COMMAND FORMAT !\n");
			isDifferentState = false;
		}
		else if (userCommand.cmd == ADD)
		{
			MainTaskList = logic.Add(MainTaskList,userTask);
			ui.showMessage("ADDED !\n");
			isDifferentState = true;
		}
		else if (userCommand.cmd == DEL)
		{
			//cout<<"HELLO?"<<endl;
			MainTaskList = logic.Delete(MainTaskList,DisplayTaskList,userCommand.idx);
			if (logic.success == 1)
			{
				isDifferentState = true;
				ui.showMessage("DELETED !\n");
			}
			else 
			{
				ui.showFailureMessage();
				isDifferentState = false;
			}

		}
		else if (userCommand.cmd == SEARCH)
		{
			isDifferentState = false;
			DisplayTaskList = logic.Search(MainTaskList,userTask);

			if (logic.success == 1)
			{
				ui.showMessage("\n");
				ui.showTaskList(DisplayTaskList);
			}
			else ui.showFailureMessage();
			
		}
		else if (userCommand.cmd == DISPLAY)
		{
			isDifferentState = false;
			DisplayTaskList = logic.Display(MainTaskList,userTask,userCommand.instruction);
			//for (int i = 0; i < DisplayTaskList.size(); i++) cout<<DisplayTaskList[i].isDone<<endl;

			//if (logic.success == 1)
			if (true)
			{
				ui.showMessage("\n");
				ui.showTaskList(DisplayTaskList);
			}
			else ui.showFailureMessage();
		}
		else if (userCommand.cmd == EDIT)
		{
			MainTaskList = logic.Edit(MainTaskList,DisplayTaskList,userCommand.idx[0],userTask);

			if (logic.success == 1)
			{
				isDifferentState = true;
				ui.showMessage("EDITED !\n");
			}
			else
			{
				ui.showFailureMessage();
				isDifferentState = false;
			}
		}
		else if (userCommand.cmd == EXIT)
		{
			ui.showExitMessage();
			exit(0);
		}
		else if (userCommand.cmd == CLS)
		{
			system("CLS");
			isDifferentState = false;

		}
		else if (userCommand.cmd == DONE)
		{
			MainTaskList = logic.Done(MainTaskList,DisplayTaskList,userCommand.idx);

			//for (int i = 0; i < MainTaskList.size(); i++) cout<<MainTaskList[i].isDone<<endl;
			if (logic.success == 1)
			{
				isDifferentState = true;
				ui.showMessage("DONE !\n");
			}
			else 
			{
					ui.showFailureMessage();
					isDifferentState = false;
			}
		}
		else if (userCommand.cmd == UNDONE)
		{
			MainTaskList = logic.Undone(MainTaskList,DisplayTaskList,userCommand.idx);

			//for (int i = 0; i < MainTaskList.size(); i++) cout<<MainTaskList[i].isDone<<endl;
			if (logic.success == 1)
			{
				isDifferentState = true;
				ui.showMessage("UNDONE !\n");
			}
			else 
			{
					ui.showFailureMessage();
					isDifferentState = false;
			}
		}
		else if (userCommand.cmd == UNDO)
		{
			history.undo();
			MainTaskList = history.undo();

			isDifferentState = true;

			ui.showMessage("DONE !\n");
		}
		else if (userCommand.cmd == HELP)
		{
			isDifferentState = false;
			ui.showHelp();
		}

		// JUST WRITE TO FILE, UPDATE LAST VERSION
		
		if (isDifferentState) storage.writeToFile(MainTaskList);

	}
	
	getchar();

	return 0;
}
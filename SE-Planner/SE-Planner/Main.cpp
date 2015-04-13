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
	vector<Task> MainTaskList;
	vector<Task> DisplayTaskList;
	vector<Task> LastStateTaskList;

	MainTaskList.clear();
	DisplayTaskList.clear();
	LastStateTaskList.clear();
	UI ui;
	Storage storage = Storage();

	Parser parser;
	Logic logic;
	History history = History();


	while (true) 
	{
		// read from file
		MainTaskList = storage.getAllTask();
		LastStateTaskList = MainTaskList;

		// Color White for clarity
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,15);
		string userString = ui.getInput();

		parser = Parser(userString);

		Command userCommand = parser.getCommand();
		Task userTask = parser.getTask();


		// MAIN COMMAND SWITCH

		if (userCommand.cmd == INVALID) {
			ui.showFailureMessage();
			history.isNewState = false;
		}

		else if (userCommand.cmd == ADD) {
			MainTaskList = logic.Add(MainTaskList,userTask);
			ui.showMessage("ADDED !\n");
			history.isNewState = true;
		}

		else if (userCommand.cmd == DEL) {
			MainTaskList = logic.Delete(MainTaskList,DisplayTaskList,userCommand.idx);
			if (logic.success == OPERATION_SUCCEEDED) {
				history.isNewState = true;
				ui.showMessage("DELETED !\n");
			}
			else {
				ui.showFailureMessage();
				history.isNewState = false;
			}

		}

		else if (userCommand.cmd == SEARCH) {
			history.isNewState = false;
			DisplayTaskList = logic.search(MainTaskList,userTask);

			if (logic.success == OPERATION_SUCCEEDED) {
				ui.showMessage("\n");
				ui.showTaskList(DisplayTaskList);
			}
			else {
				ui.showFailureMessage();
			}
			
		}

		else if (userCommand.cmd == DISPLAY) {
			history.isNewState = false;
			DisplayTaskList = logic.display(MainTaskList,userTask,userCommand.instruction);
	
			ui.showTaskList(DisplayTaskList);
		}

		else if (userCommand.cmd == EDIT) {
			MainTaskList = logic.edit(MainTaskList,DisplayTaskList,userCommand.idx[0],userTask);

			if (logic.success == OPERATION_SUCCEEDED) {
				history.isNewState = true;
				ui.showMessage("EDITED !\n");
			}
			else {
				ui.showFailureMessage();
				history.isNewState = false;
			}
		}

		else if (userCommand.cmd == EXIT) {
			ui.showExitMessage();
			exit(0);
		}

		else if (userCommand.cmd == CLS) {
			system("CLS");
			history.isNewState = true;

		}

		else if (userCommand.cmd == DONE) {
			MainTaskList = logic.Done(MainTaskList,DisplayTaskList,userCommand.idx);

			if (logic.success == OPERATION_SUCCEEDED) {
				history.isNewState = true;
				ui.showMessage("DONE !\n");
			}
			else {
				ui.showFailureMessage();
				history.isNewState = false;
			}
		}

		else if (userCommand.cmd == UNDONE) {
			MainTaskList = logic.Undone(MainTaskList,DisplayTaskList,userCommand.idx);

			if (logic.success == OPERATION_SUCCEEDED) {
				history.isNewState = true;
				ui.showMessage("UNDONE !\n");
			}
			else {
				ui.showFailureMessage();
				history.isNewState = false;
			}
		}

		else if (userCommand.cmd == UNDO) {

			if (history.canUndo()) {
				MainTaskList = history.undoState();
				ui.showMessage("DONE !\n");
			}
			else {
				ui.showMessage("CAN'T UNDO !\n");
			}
			

			history.isNewState = true;
			
		}

		else if (userCommand.cmd == HELP) {
			history.isNewState = false;
			ui.showHelp();
		}

		else if (userCommand.cmd == USE) {
			bool isNewPathOK = storage.setOutputFilePath(userCommand.path);

			if (isNewPathOK) {
					ui.showMessage("Changed !\n");
					history.clearState();
			}
			else {
					ui.showFailureMessage();
			}

			history.isNewState = false;
			
		}

		else if (userCommand.cmd == WHERE) {
			history.isNewState = false;
			ui.showMessage(storage.getOutputFilePath()+"\n");
		}

		// JUST WRITE TO FILE, UPDATE LAST VERSION
		if (history.isNewState)  {
			storage.writeToFile(MainTaskList);
			if (userCommand.cmd != UNDO) history.pushState(LastStateTaskList);
		}

	}
	

	return 0;
}
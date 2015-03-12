#include "UI.h"
#include "Logic.h"
#include "Parser.h"
#include "Storage.h"

int main(void) {
	UI ui;
	Logic logic;
	Parser paser;
	Storage storage;

	while(1) {
		std::string message;
		cin >> message;

		//ui.setInputedMessage(message);
		//logic.setInpuedMessage(ui.getInputedMessage());
		//parser
		//logic.getCommand();
		//logic.getTask();
		//logic.executeCommand(storage.getAllTask());
		//storage.writeToFile(storage.getAllTask());
		//ui.printMessage(logic.getCommand(), logic.getTask(), logic.getDisplayedTaskList());
	}

	return 0;
}
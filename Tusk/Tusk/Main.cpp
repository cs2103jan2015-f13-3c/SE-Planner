#include "UI.h"
#include "Logic.h"
#include "Parser.h"
#include "Storage.h"

int main(void) {
	UI ui;
	Logic logic;
	Parser parser;
	Storage storage;

	while (true)
	{
		// command loop
		ui.setInputedMessage();
		logic.setInpuedMessage(ui.getInputedMessage());

		pair<Command, Task> userCommand = parser.parseUserInput(ui.getInputedMessage());

		logic.setCommand(userCommand.first);
		logic.setTask(userCommand.second);

		logic.setMainTaskList(storage.getAllTask());
		vector<Task> debug1 = logic.getMainTaskList();
		//cout<<"Size of main task list before command == "<<debug1.size()<<endl;

		logic.executeCommand();
		
		vector<Task> debug = logic.getMainTaskList();
		//cout<<"Size of main task list after command == "<<debug.size()<<endl;

		storage.writeToFile(logic.getMainTaskList());

		ui.setOutputedMessage(userCommand.first, logic.getTask(), logic.getDisplayedTaskList());
		ui.printOutputedMessage();

	}
	

	getchar();

	return 0;
}
#include "Logic.h"

Logic::Logic(void) {
	_myStorage = new Storage;
	_myParser = new Parser;
}

Logic::~Logic(void) {
}

void Logic::initializeVector() {
	//_myVector=_myStorage->getAllTask();
}

void Logic::getCommandData(const string input) {
	//_commandType = _myParser->getCommandType();
	//_taskTitle = _myParser->getTaskTitle();
	//_taskType = _myParser->getTaskType();
}

void Logic::executeCommand() {
	switch(_commandType) {
	case Create:
		createTask();
		break;
	case Read:
		break;
	case Update:
		break;
	case Delete:
		deleteTask();
		break;
	}

}

//Later remove this method!!!
Task Logic::getTask() {
	Task newTask;

	newTask.inputTaskType(Deadline);
	newTask.inputTitle("testTask");

	return newTask;
}

Task Logic::generateTask() {
	Task newTask;
	newTask.inputTaskType(_taskType);
	newTask.inputTitle(_taskTitle);

	return newTask;
}

int Logic::convertToInteger(const string input) {
	int output=0;
	for(int i=0;i<input.size();i++) {
		if(isdigit(input[i])) {
			output*=10;
			output+=(input[i]-'0');
		}
		else {
			return 0;
		}
	}

	return output;
}

void Logic::createTask() {
	//Remove this line as well!!!
	Task newTask = getTask();

	CreateTask *createTaskObject = new CreateTask(generateTask());

	createTaskObject->execute(_myVector);

	//_myStorage->writeToFile(_myVector);

}
void Logic::deleteTask(){
	DeleteTask *deleteTaskObject = new DeleteTask(convertToInteger(_taskTitle));

	deleteTaskObject->execute(_myVector);

	//_myStorage->writeToFile(_myVector);
}



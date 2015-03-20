#include "Edit.h"

Edit::Edit(void) {
}

Edit::~Edit(void) {
}

std::vector<Task> Edit::execute() {
	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	Task task;
	task = _displayedTaskList[_index-1];

	for (int i = 0; i < taskList.size(); i++) {
		if (taskList[i].getTitle() == task.getTitle()) {
			taskList[i] = task;
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(task);

	return _result;
}



/*void Edit::executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task>& displayedTaskList)
{
	//cout<<"What I get from WM="<<task.getTitle()<<endl;
	string newTitle = task.getTitle().substr(2);
	//cout<<"New title = "<<newTitle<<endl;

	int index;
	index = std::stoi(task.getTitle(), nullptr, 10);
	task = displayedTaskList[index - 1];
	

	for (int i = 0; i < mainTaskList.size(); i++)
	{
		//cout<<"Current Title = "<<mainTaskList[i].getTitle()<<endl;
		if (mainTaskList[i].getTitle() == task.getTitle())
		{
			//cout<<"Matched"<<endl;
			mainTaskList[i].setTitle(newTitle);
		}
	}
}*/
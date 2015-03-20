#include "Edit.h"

#include <iostream>

using namespace std;

Edit::Edit(void) {
}

Edit::~Edit(void) {
}

void Edit::executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task>& displayedTaskList)
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
}
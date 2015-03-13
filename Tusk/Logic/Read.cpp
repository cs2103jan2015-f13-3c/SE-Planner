#include "Read.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Read::Read(void) {
}

Read::~Read(void) {
}

std::vector<Task> Read::executeCommand(std::vector<Task>& mainTaskList, Task& task)
{
	vector<Task> displayedTaskList;

	string keyword = task.getTitle();

	int totalDisplay = 0;

	for (int i = 0; i < mainTaskList.size(); i++)
	{
		//cout<<"Current Title = "<<mainTaskList[i].getTitle()<<endl;
		//cout<<"Check keyword = "<<keyword<<endl;

		if (mainTaskList[i].getTitle().find(keyword) != string::npos)
		{
			//cout<<"Matched"<<endl;
			displayedTaskList.push_back(mainTaskList[i]);
			totalDisplay++;
		}

		if (totalDisplay == 9) break;
	}

	//cout<<"Display Task List after Read Command = "<<displayedTaskList.size()<<endl;
	return displayedTaskList;

}
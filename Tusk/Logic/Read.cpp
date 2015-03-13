#include "Read.h"
#include <vector>
#include <string>

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
		if (mainTaskList[i].getTitle().find(keyword) != string::npos)
		{
			displayedTaskList.push_back(mainTaskList[i]);
			totalDisplay++;
		}

		if (totalDisplay == 9) break;
	}

	return displayedTaskList;

}
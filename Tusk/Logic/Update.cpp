#include "Update.h"


using namespace std;

Update::Update(void) {
}

Update::~Update(void) {
}

void executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task>& displayedTaskList)
{
	int index;
	index = std::stoi(task.getTitle(), nullptr, 10);
	task = displayedTaskList[index - 1];

	string newTitle = task.getTitle().substr(2);

	for (int i = 0; i < mainTaskList.size(); i++)
	{
		if (mainTaskList[i].getTitle() == task.getTitle())
		{
			mainTaskList[i].setTitle(newTitle);
		}
	}
}
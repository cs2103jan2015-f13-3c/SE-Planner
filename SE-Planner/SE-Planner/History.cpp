#include "History.h"


History::History(void)
{
	while (!TaskStack.empty()) TaskStack.pop();
}


History::~History(void)
{
}

void History::push(vector<Task> newState)
{
	TaskStack.push(newState);
}

vector<Task> History::undo()
{
	vector<Task> ret = TaskStack.top();
	TaskStack.pop();
	return ret;
}

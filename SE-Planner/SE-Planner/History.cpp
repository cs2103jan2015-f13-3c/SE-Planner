#include "History.h"


History::History(void)
{
	while (!TaskStack.empty()) TaskStack.pop();
	isNewState = true;
}


History::~History(void)
{
}

void History::pushState(vector<Task> newState)
{
	TaskStack.push(newState);
}

void History::clearState()
{
	while (!TaskStack.empty()) TaskStack.pop();
}

bool History::canUndo()
{
	return (!TaskStack.empty());
}
vector<Task> History::undoState()
{
	vector<Task> ret = TaskStack.top();
	TaskStack.pop();
	return ret;
}

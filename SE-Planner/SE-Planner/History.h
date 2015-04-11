#pragma once

#include "Common.h"
#include <vector>
#include <stack>

class History
{
public:
	History(void);
	~History(void);

	stack< vector<Task> > TaskStack;

	void pushState(vector<Task>);
	vector<Task> undoState(void);
	void clearState();
	bool canUndo(void);

	bool isNewState;

};


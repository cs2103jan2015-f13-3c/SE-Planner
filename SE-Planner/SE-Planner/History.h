#pragma once

#include "Common.h"
#include <vector>
#include <stack>
//@author A0116724J
class History 
{
public:
	History(void);
	~History(void);

	stack< vector<Task> > StateStack;

	void pushState(vector<Task>);
	vector<Task> undoState(void);
	void clearState();
	bool canUndo(void);

	bool isNewState;

};


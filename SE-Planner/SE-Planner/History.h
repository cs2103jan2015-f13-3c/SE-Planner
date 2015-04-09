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

	void push(vector<Task>);
	vector<Task> undo(void);

};


#include "History.h"
#include <assert.h>

/*
	@desc: clear stack for safety
*/
History::History(void) {
	while (!StateStack.empty()) StateStack.pop();
	isNewState = true;
}


History::~History(void) {
}

/*
	@desc: push new program state
*/
void History::pushState(vector<Task> newState) {
	StateStack.push(newState);
}

void History::clearState() {
	while (!StateStack.empty()) StateStack.pop();
}

bool History::canUndo() {
	return (!StateStack.empty());
}

/*
	@desc: undo to previous state
*/
vector<Task> History::undoState() {
	assert(canUndo());
	vector<Task> ret = StateStack.top();
	StateStack.pop();
	return ret;
}

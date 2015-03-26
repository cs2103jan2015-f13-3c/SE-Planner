#include <algorithm>
#include "Search.h"

Search::Search(void) {
}

Search::~Search(void) {
}

std::vector<Task> Search::execute() {
	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		string::iterator iter;
		iter = search(taskList[i].getTitle().begin(), taskList[i].getTitle().end(), _information.begin(), _information.end());
		if (iter != taskList[i].getTitle().end()) {
			_result.push_back(taskList[i]);
		}
	}

	return _result;
}

void Search::setInformation(std::string information) {
	_information = information;
}
#include "TaskParser.h"

TaskParser::TaskParser(void) {
}

TaskParser::~TaskParser(void) {
}

Task TaskParser::getTask() {
	return _task;
}

bool TaskParser::parseTask(std::string taskInput) {
	int timePos = taskInput.find("time:");
	int datePos = taskInput.find("date:");
	bool executionResult;

	//Indicating that task is a floating task
	if ((timePos == -1) && (datePos == -1)) {
		executionResult = _timeParser.parseTime("");

		//Check if time is parsed correctly
		if (!executionResult) {
			return false;
		}

		executionResult = _dateParser.parseDate("");

		//Check if date is parsed correctly
		if (!executionResult) {
			return false;
		}

		//Input taskType and description for task
		_task.setTaskType(FLOATINGTASK);
		_task.setDescription(taskInput);

	//Indicating that task is a deadline that should not have a range
	} else if ((timePos == -1) && (datePos != -1)) {
		executionResult = _timeParser.parseTime("2359"); //Default to 2359

		//Check if time is parsed correctly
		if (!executionResult) {
			return false;
		}

		//Obtain date data to be input into dateParser
		std::string date = taskInput.substr(datePos, taskInput.size() - datePos);
		std::string dateData = date.substr(5, date.size() - 5);
		//Remove all white spacing in date data
		int spacePos = dateData.find(" ");
		while (spacePos != -1) {
			dateData.erase(dateData.begin() + spacePos);
			spacePos = dateData.find(" ");
		}

		//Check if date is not in XX/XX/XXXX format
		if (dateData.size() > 10) {
			return false;
		}

		//Input date data into dateParser
		executionResult = _dateParser.parseDate(dateData);

		//Check if date is parsed correctly
		if (!executionResult) {
			return false;
		}

		//Input taskType of task
		_task.setTaskType(DEADLINE);

		//Input description of task
		std::string description = taskInput.substr(0, taskInput.size() - date.size());
		_task.setDescription(description);

	//Indicating task can be a deadline or timed task
	} else {
		//Check whether time is input before date
		if (datePos > timePos) {
			//Obtain date data to be input into dateParser first
			std::string date = taskInput.substr(datePos, taskInput.size() - datePos);
			std::string dateData = date.substr(5, date.size() - 5);
			//Remove all white spacing in date data
			int spacePos = dateData.find(" ");
			while (spacePos != -1) {
				dateData.erase(dateData.begin() + spacePos);
				spacePos = dateData.find(" ");
			}
			//Input date data into dateParser
			executionResult = _dateParser.parseDate(dateData);

			//Check if date is parsed correctly
			if (!executionResult) {
				return false;
			}

			//Obtain remaing task details
			std::string remainingTask = taskInput.substr(0, taskInput.size() - date.size());

			//Obtain time data to be input into timePaser next
			std::string time = remainingTask.substr(timePos, remainingTask.size() - timePos);
			std::string timeData = time.substr(5, time.size() - 5);
			//Remove all white spacing in time data
			spacePos = timeData.find(" ");
			while (spacePos != -1) {
				timeData.erase(timeData.begin() + spacePos);
				spacePos = timeData.find(" ");
			}

			//Input time data into timeParser
			executionResult = _timeParser.parseTime(timeData);

			//Check if time is parsed correctly
			if (!executionResult) {
				return false;
			}

			//Input description of task
			std::string description = taskInput.substr(0, taskInput.size() - date.size() - time.size());
			_task.setDescription(description);

			_task.setStartingTime(_timeParser.getStartingTime());
			_task.setEndingTime(_timeParser.getEndingTime());
			_task.setStartingDate(_dateParser.getStartingDate());
			_task.setEndingDate(_dateParser.getEndingDate());
			_task.setIsDone(false);

		//When date is input before time
		} else {
			//Obtain time data to be input into timeParser first
			std::string time = taskInput.substr(timePos, taskInput.size() - timePos);
			std::string timeData = time.substr(5, time.size() - 5);
			//Remove all white spacing in time data
			int spacePos = timeData.find(" ");
			while (spacePos != -1) {
				timeData.erase(timeData.begin() + spacePos);
				spacePos = timeData.find(" ");
			}
			//Input time data into timeParser
			executionResult = _timeParser.parseTime(timeData);

			//Check if time is parsed correctly
			if (!executionResult) {
				return false;
			}

			//Obtain remaing task details
			std::string remainingTask = taskInput.substr(0, taskInput.size() - time.size());

			//Obtain date data to be input into datePaser next
			std::string date = remainingTask.substr(datePos, remainingTask.size() - datePos);
			std::string dateData = date.substr(5, date.size() - 5);
			//Remove all white spacing in time data
			spacePos = dateData.find(" ");
			while (spacePos != -1) {
				dateData.erase(dateData.begin() + spacePos);
				spacePos = dateData.find(" ");
			}
			//Input date data into dateParser
			executionResult = _dateParser.parseDate(dateData);

			//Check if date is parsed correctly
			if (!executionResult) {
				return false;
			}

			//Input description of task
			std::string description = taskInput.substr(0, taskInput.size() - date.size() - time.size());
			_task.setDescription(description);

			_task.setStartingTime(_timeParser.getStartingTime());
			_task.setEndingTime(_timeParser.getEndingTime());
			_task.setStartingDate(_dateParser.getStartingDate());
			_task.setEndingDate(_dateParser.getEndingDate());
			_task.setIsDone(false);
		}

		//Determine if task is a deadline or timed task
		if (_task.getStartingTime().isSameAs(_task.getEndingTime())) {
			_task.setTaskType(DEADLINE);
		} else {
			_task.setTaskType(TIMEDTASK);
		}
	}

	_task.setStartingTime(_timeParser.getStartingTime());
	_task.setEndingTime(_timeParser.getEndingTime());
	_task.setStartingDate(_dateParser.getStartingDate());
	_task.setEndingDate(_dateParser.getEndingDate());
	_task.setIsDone(false);

	return true;
}
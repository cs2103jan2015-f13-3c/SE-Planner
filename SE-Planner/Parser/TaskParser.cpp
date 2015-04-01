#include "TaskParser.h"

TaskParser::TaskParser(void) {
}

TaskParser::~TaskParser(void) {
}

//Take in a string that represent a task and convert it
void TaskParser::parseTask(std::string task) {
	int timePos;
	timePos = task.find("time:");
	int datePos;
	datePos = task.find("date:");

	//When "time:" and "date:" not found indicating task is a floating task,
	if ((timePos == -1) && (datePos == -1)){
		_timeParser.parseTime("");
		_dateParser.parseDate("");

		//Input taskType and description of task
		_task.setTaskType(FLOATINGTASK);
		_task.setDescription(task);

	//When "time:" not found indicating task is a deadline
	} else if ((timePos == -1) && (datePos != -1)) {
		_timeParser.parseTime("");

		//Obtain date data to be input into dateParser
		std::string date = task.substr(datePos, task.size() - datePos);
		std::string dateData = date.substr(5, date.size() - 5);
		//Remove all white spacing in date data
		int spacePos = dateData.find(" ");
		while (spacePos != -1) {
			dateData.erase(dateData.begin() + spacePos);
			spacePos = dateData.find(" ");
		}
		//Input date data into dateParser
		_dateParser.parseDate(dateData);

		//Input taskType of task
		_task.setTaskType(DEADLINE);
		//Input description of task
		std::string description = task.substr(0, task.size() - date.size());
		_task.setDescription(description);

	//When "time:" and "date:" are found indicating task is possibly a timed task or deadline
	} else {
		//Check whether time is input before date
		if (datePos > timePos) {
			//Obtain date data to be input into dateParser first
			std::string date = task.substr(datePos, task.size() - datePos);
			std::string dateData = date.substr(5, date.size() - 5);
			//Remove all white spacing in date data
			int spacePos = dateData.find(" ");
			while (spacePos != -1) {
				dateData.erase(dateData.begin() + spacePos);
				spacePos = dateData.find(" ");
			}
			//Input date data into dateParser
			_dateParser.parseDate(dateData);

			//Obtain remaing task details
			std::string remainingTask = task.substr(0, task.size() - date.size());

			//Obtain time data to be input into timePaser next
			std::string time = remainingTask.substr(timePos, remainingTask.size() - timePos);
			std::string timeData = time.substr(5, time.size() - 5);
			//Remove all white spacing in time data
			spacePos = timeData.find(" ");
			while (spacePos != -1) {
				timeData.erase(timeData.begin() + spacePos);
				spacePos = timeData.find(" ");
			}
			//Input date data into dateParser
			_timeParser.parseTime(timeData);

			//Input description of task
			std::string description = task.substr(0, task.size() - date.size() - time.size());
			_task.setDescription(description);
		} else {
			//Obtain time data to be input into timeParser first
			std::string time = task.substr(timePos, task.size() - timePos);
			std::string timeData = time.substr(5, time.size() - 5);
			//Remove all white spacing in time data
			int spacePos = timeData.find(" ");
			while (spacePos != -1) {
				timeData.erase(timeData.begin() + spacePos);
				spacePos = timeData.find(" ");
			}
			//Input time data into timeParser
			_timeParser.parseTime(timeData);

			//Obtain remaing task details
			std::string remainingTask = task.substr(0, task.size() - time.size());

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
			_dateParser.parseDate(dateData);

			//Input description of task
			std::string description = task.substr(0, task.size() - date.size() - time.size());
			_task.setDescription(description);
		}

		if (_task.getStartingTime().isTimeSame(_task.getEndingTime())) {
			_task.setTaskType(DEADLINE);
		} else {
			_task.setTaskType(TIMEDTASK);
		}
	}

	//Input time and date of task
	_task.setStartingTime(_timeParser.getStartingTime());
	_task.setEndingTime(_timeParser.getEndingTime());
	_task.setStartingDate(_dateParser.getStartingDate());
	_task.setEndingDate(_dateParser.getEndingDate());
}

Task TaskParser::getTask() {
	return _task;
}
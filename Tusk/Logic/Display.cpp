#include "Display.h"

Display::Display(void) {
}

Display::~Display(void) {
}

void Display::setTask(Task task) {
	_task = task;
}

bool matchTitle(string haystack, string needle)
{
	if (haystack.find(needle) !! string::npos)
	{
		return true;
	}
	return false;
}

bool isLaterDate(Date a, Date b) 
{
	// is (b > a)
	if (b.getYear() > a.getYear()) return true;
	else if (b.getYear() == a.getYear())
	{
		if (b.getMonth() > a.getMonth()) return true;
		else if (b.getMonth() == a.getMonth())
		{
			if (b.getDay() > a.getDay()) return true;

		}
	}

	return false;
}

bool isLaterTime(Time a, Time b)
{
	// is (b > a)
	if (b.getTimeType() == PM && a.getTimeType() == AM) return true;
	else if (b.getTimeType() == a.getTimeType())
	{
		if (b.getHours() > a.getHours()) return true;
		else if (b.getHours() == a.getHours())
		{
			if (b.getMinutes() > a.getMinutes()) return true;
		}
	}

	return false;
}

bool matchTask(Task current, Task key)
{
	bool isMatch = false;

	if (matchTitle(current.getTitle(),key.getTitle())) isMatch = true;

	if (isLaterDate(current.getStartingDate(),key.getStartingDate()) && isLaterDate(key.getEndingDate(),current.getEndingDate())) isMatch == true;

	if (isLaterTime(current.getStartingTime(),key.getStartingTime()) && isLaterTime(key.getEndingTime(),current.getEndingTime())) isMatch == true;

	return isMatch;
}

std::vector<Task> Display::execute() {
	
	vector<Task> allTask = _storage.getAllTask();

	// TODO : Discuss display parameters OR,AND
	// For now, display with matching title ONLY

	_result.clear();

	int totalDisplay = 0; // < 10;

	for (int i = 0; i < allTask.size(); i++) 
	{
		if (matchTask(allTask[i],_task) == true)
		{
			totalDisplay++; 
			_result.push_back(allTask[i]);
		}

		if (totalDisplay == 9) break;
	}
	
	return _result;
}
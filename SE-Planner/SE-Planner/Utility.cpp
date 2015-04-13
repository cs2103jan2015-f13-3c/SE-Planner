#include "Utility.h"
#include <fstream>

Utility::Utility(void)
{
}


Utility::~Utility(void)
{
}
//@author A0116724J
/*
@desc: Is DD/MM/YYYY a valid date?
*/
bool Utility::isValidDate(Date z) {
	int d = z.day;
	int m = z.month;
	int y = z.year;

	// IF I FOLLOW CODING CONVENTION, THIS PART WILL BE DISASTER TO READ
	if (! (1<= m && m<=12) ) return false;
	if (! (1<= d && d<=31) ) return false;
	if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) ) return false;
	if ( (d==30) && (m==2) ) return false;
	if ( (m==2) && (d==29) && (y%4!=0) ) return false;
	if ( (m==2) && (d==29) && (y%400==0) ) return true;
	if ( (m==2) && (d==29) && (y%100==0) ) return false;
	if ( (m==2) && (d==29) && (y%4==0)  ) return true;

	return true;
}

/*
@desc: Is HH/MM a valid time?
*/
bool Utility::isValidTime(Time z) {
	int hh = z.hour;
	int mm = z.min;

	if (hh < 0 || hh >= 24) return false;
	if (mm < 0 || mm >= 60) return false;

	return true;
}

/*
@desc: Is second date >= first date
*/
bool Utility::isLaterDate(Date first, Date second) {
	int day1 = first.day;
	int month1 = first.month;
	int year1 = first.year;

	int day2 = second.day;
	int month2 = second.month;
	int year2 = second.year;

	if (year1 != year2) {
		return year2 > year1;
	}
	else if (month1 != month2) {
		return month2 > month1;
	}
	else return (day2 >= day1);
}

/*
@desc: Is second time >= first time
*/
bool Utility::isLaterTime(Time first, Time second) {
	int h1 = first.hour;
	int m1 = first.min;

	int h2 = second.hour;
	int m2 = second.min;

	if (h1 != h2) {
		return h2 > h1;
	}
	else return m2 >= m1;
}

/*
@desc: Are two dates different
*/
bool Utility::isDiffDate(Date first, Date second) {
	if (first.day != second.day || first.month != second.month || first.year != second.year) return true;
	return false;
}

bool Utility::isNotNullDate(Date z) {
	if (z.day != -1 && z.month != -1 && z.year != -1) return true;
	return false;
}

bool Utility::isNotNullTime(Time z) {
	if (z.hour != -1 && z.min != -1) return true;
	return false;
}

bool Utility::isNull(string x) {
	return (x == "");
}

bool Utility::isNull(Date x) {
	return (x.day == -1 && x.month == -1 && x.year == -1);
}

bool Utility::isNull (Time x) {
	return (x.hour == -1 && x.min == -1);
}

bool Utility::isEqual(Date d1, Date d2) {
	return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}

bool Utility::isEqual(Time t1, Time t2) {
	return (t1.hour == t2.hour && t1.min == t2.min);
}


/*
@desc: Is all information of the task about to added valid?
*/
bool Utility::isValidAddTask(Task x) {
	bool isOK = true;

	if (isNull(x.title)) isOK = false;

	if (x.taskType == FLOATTASK) {
	}

	if (x.taskType == DEAD) {
		if (!isValidDate(x.startDate)) isOK = false;
		if (!isValidTime(x.startTime)) isOK = false;
	}

	if (x.taskType == TIMED) {
		if (!isValidDate(x.startDate)) isOK = false;
		if (!isValidTime(x.startTime)) isOK = false;

		if (!isValidDate(x.endDate)) isOK = false;
		if (!isValidTime(x.endTime)) isOK = false;

		if (isLaterDate(x.startDate,x.endDate)) {
			if (!isDiffDate(x.startDate,x.endDate))
				if (!isLaterTime(x.startTime,x.endTime)) isOK = false;
		}
		else isOK = false;
	}

	return isOK;
}

/*
@desc: Test whether task2 is a substring of task1
*/
bool Utility::compareTitle(Task task1, Task task2) {
	if (isNull(task2.title)) return true;
	else return (task1.title.find(task2.title) != string::npos);
}

/*
@desc: Are the dates searched for (task2) match date in task1 
*/
bool Utility::compareDate(Task task1, Task task2) {
	if (isNull(task1.startDate) && isNull(task2.startDate)) return true;
	else {
		if (!isNull(task1.startDate) && !isNull(task2.startDate)) {
			return isEqual(task1.endDate,task2.endDate) && isEqual(task1.startDate,task2.startDate);
		}
		else  {
			if (isNull(task2.startDate)) return true;
			else return false;
		}
	}
}

/*
@desc: Are the times searched for (task2) match time in task1 
*/
bool Utility::compareTime(Task task1, Task task2) {
	if (isNull(task1.startTime) && isNull(task2.startTime)) return true;
	else {
		if (!isNull(task1.startTime) && !isNull(task2.startTime)) {
			return isEqual(task1.endTime,task2.endTime) && isEqual(task1.startTime,task2.endTime);
		}
		else  {
			if (isNull(task2.startTime)) return true;
			else return false;
		}
	}
}

bool Utility::isSame(Task t1, Task t2) {
	return (t1.title == t2.title && isEqual(t1.startDate,t2.startDate) && isEqual(t1.endDate,t2.endDate) &&
		isEqual(t1.startTime,t2.startTime) && isEqual(t1.endTime,t2.endTime));
}

/*
@desc: True if Date x1 < Date x2
*/
bool Utility::beforeToday(Date x1, Date x2) {
	// true if x1 < x2
	if (x1.year < x2.year) return true;
	else if (x1.year == x2.year) {
		if (x1.month < x2.month) return true;
		else if (x1.month == x2.month) return x1.day < x2.day;
	}

	return false;
}


/*
@desc: Are the search/edit information valid?
*/
bool Utility::isValidOtherTask(Task x) {
	bool isOK = true;

	if (x.taskType == FLOATTASK) {
	}

	if (x.taskType == DEAD) {
		if (isNotNullDate(x.startDate)) if (!isValidDate(x.startDate)) isOK = false;
		if (isNotNullTime(x.startTime)) if (!isValidTime(x.startTime)) isOK = false;
	}

	if (x.taskType == TIMED) {
		if (isNotNullDate(x.startDate)) if (!isValidDate(x.startDate)) isOK = false;
		if (isNotNullTime(x.startTime)) if (!isValidTime(x.startTime)) isOK = false;

		if (isNotNullDate(x.endDate)) if (!isValidDate(x.endDate)) isOK = false;
		if (isNotNullTime(x.endTime)) if (!isValidTime(x.endTime)) isOK = false;

		if (isNotNullDate(x.startDate) && isNotNullDate(x.endDate)) {
			if (isLaterDate(x.startDate,x.endDate)) {
				if (!isDiffDate(x.startDate,x.endDate))
					if (isNotNullTime(x.startTime) && isNotNullTime(x.endTime))
						if (!isLaterTime(x.startTime,x.endTime)) isOK = false;
			}
			else isOK = false;
		}
	}

	// need at least one field to exist
	if (x.title == "" && !isNotNullDate(x.startDate) && !isNotNullDate(x.endDate) && !isNotNullTime(x.startTime) && !isNotNullTime(x.endTime)) 
		isOK = false;

	return isOK;
}

// Logging 
void Utility::log(string logString) {
	ofstream logFile("logFile.txt", std::ios_base::out | std::ios_base::app);
	logFile<<logString<<endl;
	logFile.flush();
	logFile.close();
}
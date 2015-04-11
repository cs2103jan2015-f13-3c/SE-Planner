#include "Utility.h"
#include <fstream>

Utility::Utility(void)
{
}


Utility::~Utility(void)
{
}

bool Utility::isValidDate(Date z)
{
	int d = z.day;
	int m = z.month;
	int y = z.year;

	if (! (1<= m && m<=12) )
     return false;
	if (! (1<= d && d<=31) )
		return false;
	if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
		return false;
	if ( (d==30) && (m==2) )
		return false;
	if ( (m==2) && (d==29) && (y%4!=0) )
		return false;
	if ( (m==2) && (d==29) && (y%400==0) )
		return true;
	if ( (m==2) && (d==29) && (y%100==0) )
		return false;
	if ( (m==2) && (d==29) && (y%4==0)  )
		return true;
 
	return true;
}

bool Utility::isValidTime(Time z)
{
	int hh = z.hour;
	int mm = z.min;

	if (hh < 0 || hh >= 24) return false;
	if (mm < 0 || mm >= 60) return false;

	return true;
}


bool Utility::isLaterDate(Date first, Date second)
{
	int day1 = first.day;
	int month1 = first.month;
	int year1 = first.year;

	int day2 = second.day;
	int month2 = second.month;
	int year2 = second.year;

	if (year1 != year2)
	{
		return year2 > year1;
	}
	else if (month1 != month2)
	{
		return month2 > month1;
	}
	else return (day2 >= day1);
}

bool Utility::isLaterTime(Time first, Time second)
{
	int h1 = first.hour;
	int m1 = first.min;

	int h2 = second.hour;
	int m2 = second.min;

	if (h1 != h2)
	{
		return h2 > h1;
	}
	else return m2 >= m1;
}

bool Utility::isDiffDate(Date first, Date second)
{
	if (first.day != second.day || first.month != second.month || first.year != second.year) return true;
	return false;
}

bool Utility::isNotNullDate(Date z)
{
	if (z.day != -1 && z.month != -1 && z.year != -1) return true;
	return false;
}

bool Utility::isNotNullTime(Time z)
{
	if (z.hour != -1 && z.min != -1) return true;
	return false;
}

bool Utility::isNull(string x)
{
	return (x == "");
}

bool Utility::isNull(Date x)
{
	return (x.day == -1 && x.month == -1 && x.year == -1);
}

bool Utility::isNull (Time x)
{
	return (x.hour == -1 && x.min == -1);
}

bool Utility::isEqual(Date d1, Date d2)
{
	return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}

bool Utility::isEqual(Time t1, Time t2)
{
	return (t1.hour == t2.hour && t1.min == t2.min);
}


bool Utility::isValidAddTask(Task x)
{
	bool isOK = true;

	if (x.taskType == FLOATTASK)
	{
	}

	if (x.taskType == DEAD)
	{
		if (!isValidDate(x.startDate)) isOK = false;
		if (!isValidTime(x.startTime)) isOK = false;
	}

	if (x.taskType == TIMED)
	{
		if (!isValidDate(x.startDate)) isOK = false;
		if (!isValidTime(x.startTime)) isOK = false;

		if (!isValidDate(x.endDate)) isOK = false;
		if (!isValidTime(x.endTime)) isOK = false;

		if (isLaterDate(x.startDate,x.endDate))
		{
			if (!isDiffDate(x.startDate,x.endDate))
				if (!isLaterTime(x.startTime,x.endTime)) isOK = false;
		}
		else isOK = false;
	}

	return isOK;
}

bool Utility::compareTitle(Task task1, Task task2)
{
	
	if (isNull(task2.title)) return true;
	else return (task1.title.find(task2.title) != string::npos);
}

bool Utility::compareDate(Task task1, Task task2)
{
	if (isNull(task1.startDate) && isNull(task2.startDate)) return true;
	else
	{
		if (!isNull(task1.startDate) && !isNull(task2.startDate))
		{
			return isEqual(task1.endDate,task2.endDate);
		}
		else 
		{
			if (isNull(task2.startDate)) return true;
			else return false;
		}
	}
}

bool Utility::compareTime(Task task1, Task task2)
{
	if (isNull(task1.startTime) && isNull(task2.startTime)) return true;
	else
	{
		if (!isNull(task1.startTime) && !isNull(task2.startTime))
		{
			return isEqual(task1.endTime,task2.endTime);
		}
		else 
		{
			if (isNull(task2.startTime)) return true;
			else return false;
		}
	}
}

bool Utility::isSame(Task t1, Task t2)
{
	return (t1.title == t2.title && isEqual(t1.startDate,t2.startDate) && isEqual(t1.endDate,t2.endDate) &&
		isEqual(t1.startTime,t2.startTime) && isEqual(t1.endTime,t2.endTime));
}

bool Utility::beforeToday(Date x1, Date x2)
{
	// true if x1 < x2
	if (x1.year < x2.year) return true;
	else if (x1.year == x2.year)
	{
		if (x1.month < x2.month) return true;
		else if (x1.month == x2.month) return x1.day < x2.day;
	}

	return false;
}



bool Utility::isValidOtherTask(Task x)
{
	bool isOK = true;

	if (x.taskType == FLOATTASK)
	{
	}

	if (x.taskType == DEAD)
	{
		if (isNotNullDate(x.startDate)) if (!isValidDate(x.startDate)) isOK = false;
		if (isNotNullTime(x.startTime)) if (!isValidTime(x.startTime)) isOK = false;
	}

	if (x.taskType == TIMED)
	{
		if (isNotNullDate(x.startDate)) if (!isValidDate(x.startDate)) isOK = false;
		if (isNotNullTime(x.startTime)) if (!isValidTime(x.startTime)) isOK = false;

		if (isNotNullDate(x.endDate)) if (!isValidDate(x.endDate)) isOK = false;
		if (isNotNullTime(x.endTime)) if (!isValidTime(x.endTime)) isOK = false;

		if (isNotNullDate(x.startDate) && isNotNullDate(x.endDate))
		{
			if (isLaterDate(x.startDate,x.endDate))
			{
				if (!isDiffDate(x.startDate,x.endDate))
					if (isNotNullTime(x.startTime) && isNotNullTime(x.endTime))
					if (!isLaterTime(x.startTime,x.endTime)) isOK = false;
			}
			else isOK = false;
		}
	}

	//cout<<"ISOK = "<<isOK<<endl;
	// need at least one field to exist
	if (x.title == "" && !isNotNullDate(x.startDate) && !isNotNullDate(x.endDate) && !isNotNullTime(x.startTime) && !isNotNullTime(x.endTime)) 
		isOK = false;

	bool test1 = (x.title != "");
	bool test2 = isNotNullDate(x.startDate);
	bool test3 = isNotNullDate(x.endDate);
	bool test4 = isNotNullTime(x.startTime);
	bool test5 = isNotNullTime(x.endTime);
	//cout<<"ISOK = "<<test1<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<endl;
	return isOK;
}

void Utility::log(string logString)
{
	ofstream logFile("logFile.txt", std::ios_base::out | std::ios_base::app);
	logFile<<logString<<endl;
	logFile.flush();
	logFile.close();
}
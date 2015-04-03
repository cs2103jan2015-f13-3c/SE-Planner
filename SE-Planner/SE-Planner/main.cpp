#include <iostream>
using namespace std;

#include "TimeParser.h"
#include "DateParser.h"

int main() {
	bool result;
	TimeParser p;
	result = p.parseTime("0800-1000");
	cout << result << endl;

	/*cout << p.getStartingDate().getDay() << endl
		 << p.getStartingDate().getMonth() << endl
		 << p.getStartingDate().getYear() << endl
		 << p.getStartingDate().getIsEmpty() << endl

		 << p.getEndingDate().getDay() << endl
		 << p.getEndingDate().getMonth() << endl
		 << p.getEndingDate().getYear() << endl
		 << p.getEndingDate().getIsEmpty() << endl;*/

	cout << p.getStartingTime().getHours() << endl
		 << p.getStartingTime().getMinutes() << endl
		 << p.getStartingTime().getIsEmpty() << endl

		 << p.getEndingTime().getHours() << endl
		 << p.getEndingTime().getMinutes() << endl
		 << p.getEndingTime().getIsEmpty() << endl;

	int z;
	cin >> z;
	return 0;
}
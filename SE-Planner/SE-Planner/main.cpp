#include <iostream>
using namespace std;

#include "TimeParser.h"

int main() {
	bool result;
	TimeParser tp;
	result = tp.parseTime("");
	cout << result << endl;

	cout << tp.getStartingTime().getHours() << endl
		 << tp.getStartingTime().getMinutes() << endl
		 << tp.getStartingTime().getIsEmpty() << endl

		 << tp.getEndingTime().getHours() << endl
		 << tp.getEndingTime().getMinutes() << endl
		 << tp.getEndingTime().getIsEmpty() << endl;

	int z;
	cin >> z;
	return 0;
}
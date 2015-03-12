#include "UI.h"
#include "Logic.h"
#include "Parser.h"
#include "Storage.h"

int main(void) {
	Logic *newLogic = new Logic;

	newLogic->createTask();

	string temp;
	
	cin >> temp;  

	return 0;
}
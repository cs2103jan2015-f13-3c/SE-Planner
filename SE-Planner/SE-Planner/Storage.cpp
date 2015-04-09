#include "Storage.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Parser.h"

Storage::Storage(void){
}

Storage::Storage(string filePath){
	// currently useless
	// will implement this later
	outputFile = filePath;
}

Storage::~Storage(void){
}

// Check if the output file is ready for reading/writing. If file not exist, create one
void checkOuputFile(string outFile){
	ofstream savefile;
	savefile.open(outFile, ofstream::app);

	bool fileExist = false;
	if (savefile.good()) fileExist = true;

	if (!fileExist){
		//cout<<"SAVE FILE NOT FOUND. CREATED A NEW ONE\n";
		savefile.open(outFile, ios_base::out);
	}

	savefile.close();
}

bool setStatus(string line){
			return (line[0] == '1');
}

Task lineToParser(string line, bool DoneStatus){
	Task newTask;
	Parser parseFromFile(line);
	newTask = parseFromFile.getTask();
	newTask.isDone = DoneStatus;
			
	return newTask;
}

// GET ALL TASKS FROM FILE AND RETURN IN CORRECT FORMAT
vector<Task> Storage::getAllTask(void){
	
	checkOuputFile(outputFile);

	// open File for reading
	ifstream myfile(outputFile);
	// TODO : HANDLE EXCEPTION WHEN OPENING A FILE

	vector<Task> allTask;
	allTask.clear();

	if (myfile.is_open()){
		//cout<<"FILE OPENED"<<endl;

		string line;
		while (getline(myfile,line)){
			//cout<<"LINE READ FROM FILE: "<<line<<endl;
			// file Structure : [1/0]add ..........
			// process each line

			// GET DONE STATUS
			bool DoneStatus = false;
			DoneStatus = setStatus(line);

			// extract the add command: add ....... and pass to parser
			line = line.substr(1);
			//cout<<"LINE TO PARSER: "<<line<<endl;
			Task newTask = Task();
			newTask = lineToParser(line, DoneStatus);
			if (newTask.taskType != NUL) allTask.push_back(newTask);
		}
		myfile.close();
	}
	// return

	//cout<<"TASK READ FROM FILE = "<<allTask.size()<<endl;

	return allTask;

}

string setTimeString(int time){
	string timeStr = "";
	if(time < 10){
			timeStr = "0"+to_string(time);
	} else{
		timeStr = to_string(time);
	}
	return timeStr;
}

// convert time to String for writing to file
string timeToString(Time time){
	string out = "";
	out = setTimeString(time.hour);
	out += setTimeString(time.min);
	
	return out;
}
string setTaskDead(string TaskString, Task tempTask){
			TaskString += "date: ";
			string TaskDate = to_string(tempTask.startDate.day) + "/" + to_string(tempTask.startDate.month) + "/" + to_string(tempTask.startDate.year);
			TaskString += TaskDate;

			TaskString += " time: ";
			string TaskTime = timeToString(tempTask.startTime);
			TaskString += TaskTime;

			return TaskString;			
}

string setTaskTimed(string TaskString,Task tempTask){
	TaskString += "date: ";
			string TaskDate = to_string(tempTask.startDate.day) + "/" + to_string(tempTask.startDate.month) + "/" + to_string(tempTask.startDate.year);
			TaskString += TaskDate;
			TaskString += "-";
			TaskDate = to_string(tempTask.endDate.day) + "/" + to_string(tempTask.endDate.month) + "/" + to_string(tempTask.endDate.year);
			TaskString += TaskDate;

			TaskString += " time: ";
			string TaskTime = timeToString(tempTask.startTime);
			TaskString += TaskTime;
			TaskString += "-";
			TaskTime = timeToString(tempTask.endTime);
			TaskString += TaskTime;
			return TaskString;
}

string setIsDone(Task tempTask, string TaskString){
	if (tempTask.isDone == true){
		TaskString += "1";
	} else {
		TaskString += "0";
	}
	return TaskString;
}

// convert task to string for writing to file
string convertToString(Task tempTask){
	//Task tempTask = Task();

	string TaskString = "";

	// isDone Status
	TaskString = setIsDone(tempTask, TaskString);
	// add
	TaskString += "add ";
	// Title
	TaskString += tempTask.title;
	
	if (tempTask.taskType != FLOATTASK){
		TaskString += " ";

		// Deadline
		if (tempTask.taskType == DEAD){
			TaskString = setTaskDead(TaskString, tempTask);
		}
		// Timed

		if (tempTask.taskType == TIMED){
			TaskString = setTaskTimed(TaskString, tempTask);
			}
	}
	
	return TaskString;
}

void Storage::writeToFile(vector<Task> allTask){
	ofstream myfile;
	myfile.open(outputFile);

	if (myfile.is_open()){
		//cout<<"WRITING TO FILE"<<endl;
		//cout<<"TASK WRITTEN TO FILE = "<<allTask.size()<<endl;

		for (int i = 0; i < allTask.size(); i++){
			string out = convertToString(allTask[i]);
			//cout<<allTask[i].isDone<<endl;
			//cout<<"CONVERTED = "<<out<<endl;
			//out = "test";
			myfile << out << endl;
		}
		myfile.flush();
		myfile.close();
	}
}

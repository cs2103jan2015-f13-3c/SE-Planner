#include "ParserLog.h"


ParserLog::ParserLog(void){
}


ParserLog::~ParserLog(void){
}

void ParserLog::start(){
	_outFile.open("parser_log", std::ios::app);
	if (_outFile.is_open()) {
		_outFile << "log started..." << "\n";
	}

}

void ParserLog::write(std::string message){
	if (_outFile.is_open()) {
		_outFile << message << "\n";
	}

}


void ParserLog::end(){
	if (_outFile.is_open()) {
		_outFile << "log end" << "\n";
		}

	_outFile.close();
}
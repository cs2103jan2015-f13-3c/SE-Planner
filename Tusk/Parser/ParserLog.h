#pragma once
#include <string>
#include <fstream>

std::ofstream _outFile ("parser_log", std::ios::app);	
;

class ParserLog
{
public:
	ParserLog(void);
	~ParserLog(void);

	void start();
	void write(std::string);
	void end();

};


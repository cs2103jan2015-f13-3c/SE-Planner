#pragma once
#include <string>
#include <fstream>



class ParserLog{
public:
	ParserLog(void);
	~ParserLog(void);

	void start();
	void write(std::string);
	void end();

private:
	std::ofstream _outFile;	


};


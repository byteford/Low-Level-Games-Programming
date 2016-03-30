#include "Logger.h"
static std::string Folder;
static std::ofstream* outStream;

Logger::Logger()
{
}


Logger::~Logger()
{
}
void Logger::SetFolder(std::string Fname){
	Folder = Fname;
	std::stringstream temp;
	temp << Fname << "\\output.log";
	outStream = new std::ofstream(temp.str().c_str(), std::ios::out);
}
void Logger::output(std::string out){
	std::cout << out;
}
void Logger::output(std::stringstream* out){
	output(out->str());
}
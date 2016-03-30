#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
class Logger
{
public:
	Logger();
	~Logger();
	static void SetFolder(std::string Fname);
	static void output(std::string out);
	static void output(std::stringstream* out);
};


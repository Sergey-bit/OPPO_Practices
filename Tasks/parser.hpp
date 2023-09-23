#pragma once

#include <string>

class Parser
{
public:
	virtual unsigned getUint() = 0;
	virtual std::string getStringInf() = 0;
	virtual void updateParsingData(const std::string&) = 0;

};
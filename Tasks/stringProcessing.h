#pragma once

#include "parser.hpp"

class StringProcessing : virtual public Parser
{
public:
	virtual unsigned getUint();
	virtual std::string getStringInf();
	virtual void updateParsingData(const std::string&);

private:
	std::string data_;
	size_t index_ = 0;
};
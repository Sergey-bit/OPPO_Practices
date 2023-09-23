#include "stringProcessing.h"

unsigned StringProcessing::getUint()
{
	std::string ret;

	while (index_ < data_.length() && !isdigit(data_[index_])) ++index_;
	while (index_ < data_.length() && isdigit(data_[index_]))
	{
		ret += data_[index_++];
	}

	return std::atoi(ret.c_str());
}
std::string StringProcessing::getStringInf()
{
	std::string ret;

	while (index_ < data_.length() && data_[index_++] != '\"');
	while (index_ < data_.length() && data_[index_] != '\"')
	{
		ret += data_[index_++];
	}

	if (!index_ || index_ == data_.length())
	{
		throw std::exception::exception("Invalid data. Missed \" or data is \"\"");
	}

	return ret;
}
void StringProcessing::updateParsingData(const std::string& data)
{
	data_ = data;
	index_ = 0;
}
#include "ListOfLessons.hpp"

inline unsigned getUint(std::string& data);
inline std::string getStringInf(std::string& data);

ListOfLessons::ListOfLessons()
{

}
ListOfLessons::ListOfLessons(const std::vector<StLesson*>& lessons) : lessons_(lessons)
{

}
ListOfLessons::~ListOfLessons()
{
	for (StLesson* lesson : lessons_)
	{
		delete lesson;
	}
}

void ListOfLessons::readFile(const std::string& filename)
{
	std::ifstream in(filename);
	std::string data;

	if (!in.is_open())
	{
		throw std::exception::exception(("Failed to open the file \"" + filename + "\"").c_str());
		return;
	}
	while(std::getline(in, data))
	{
		StLesson* lesson = new StLesson();

		{
			Date date = { 0 };

			date.year = getUint(data);
			date.month = getUint(data) - 1;
			date.day = getUint(data);

			lesson->setDate(date);
		}

		lesson->setClassroom(getStringInf(data));
		lesson->setTeacherName(getStringInf(data));

		lessons_.push_back(lesson);
	}
}
void ListOfLessons::print() const noexcept
{
	for (const StLesson* lesson : lessons_)
	{
		lesson->print();
	}
}

// gives first integer in the given string
inline unsigned getUint(std::string& data)
{
	std::string ret;
	size_t index = 0;

	while (index < data.length() && !isdigit(data[index])) ++index;
	while (index < data.length() && isdigit(data[index]))
	{
		ret += data[index++];
	}
	data = data.substr(index);

	return std::atoi(ret.c_str());
}
inline std::string getStringInf(std::string& data)
{
	std::string ret;
	size_t index = 0;

	while (index < data.length() && data[index++] != '\"');
	while (index < data.length() && data[index] != '\"')
	{
		ret += data[index++];
	}
	
	if (!index || index == data.length())
	{
		throw std::exception::exception("Invalid data. Missed \"");
		return "";
	}
	data = data.substr(++index);
	
	return ret;
}
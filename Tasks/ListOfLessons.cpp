#include "ListOfLessons.hpp"

inline void fillDate(Date&, Parser*);

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

void ListOfLessons::readFile(const std::string& filename, Parser* handler)
{
	std::ifstream in(filename);
	std::string data;

	if (!in.is_open())
	{
		throw std::exception::exception(("Failed to open the file \"" + filename + "\"").c_str());
	}
	while(std::getline(in, data))
	{
		StLesson* lesson = new StLesson();

		handler->updateParsingData(data);
		{
			Date date = { 0 };

			fillDate(date, handler);
			lesson->setDate(date);
		}

		lesson->setClassroom(handler->getStringInf());
		lesson->setTeacherName(handler->getStringInf());

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
inline void fillDate(Date& fillingStruct, Parser* handler)
{
	fillingStruct.year = handler->getUint();
	fillingStruct.month = handler->getUint();
	fillingStruct.day = handler->getUint();
}
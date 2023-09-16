#include "Object.hpp"

bool Validation::isValid() const noexcept
{
	return valid;
}

StLesson::StLesson(
	const Date& when,
	const std::string& classroom,
	const std::string& teacherName
) : when_(when), classroom_(classroom), teacherName_(teacherName)
{

}

void StLesson::setValid(bool val) noexcept
{
	valid = val;
}

std::string StLesson::getDate() const noexcept
{
	if (!isValid())
	{
		return "-----";
	}
	return std::to_string(when_.year) + ":" + 
		std::to_string(when_.month) + ":" + 
		std::to_string(when_.day);
}
std::string StLesson::getClassroom() const noexcept
{
	if (!isValid())
	{
		return "-----";
	}
	return classroom_;
}
std::string StLesson::getTeacherName() const noexcept
{
	if (!isValid())
	{
		return "-----";
	}
	return teacherName_;
}

void StLesson::setDate(const Date& when) noexcept
{
	when_ = when;
	if (!isValid() && !classroom_.empty() && !teacherName_.empty())
	{
		setValid(true);
	}
}
void StLesson::setClassroom(const std::string& classroom) noexcept
{
	classroom_ = classroom;
	if (!isValid() && classroom_.empty() && !teacherName_.empty())
	{
		setValid(true);
	}
}
void StLesson::setTeacherName(const std::string& teacherName) noexcept
{
	teacherName_ = teacherName;
	if (!isValid() && !classroom_.empty() && teacherName_.empty())
	{
		setValid(true);
	}
}

std::ostream& StLesson::print() const noexcept
{
	return std::cout
		<< "Date: " << getDate()
		<< " | Classroom name: " << getClassroom()
		<< " | Teacher name: " << getTeacherName()
		<< "\n";
}
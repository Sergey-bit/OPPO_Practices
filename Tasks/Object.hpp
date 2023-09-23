#pragma once

#include <chrono>
#include <string>
#include <iostream>

struct Date
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
};
struct Validation
{
	bool valid;

protected:
	virtual ~Validation() { }
	virtual void setValid(bool) = 0;

public:
	bool isValid() const noexcept;
};

class StLesson : virtual public Validation
{
public:
	StLesson(
		const Date& when = { 0 },
		const std::string& classroom = "_",
		const std::string& teacherName = "_"
	);

	virtual void setValid(bool) noexcept;

	std::string getDate() const noexcept;
	std::string getClassroom() const noexcept;
	std::string getTeacherName() const noexcept;

	void setDate(const Date&) noexcept;
	void setClassroom(const std::string&) noexcept;
	void setTeacherName(const std::string&) noexcept;

	std::ostream& print() const noexcept;

private:
	Date when_;
	std::string classroom_;
	std::string teacherName_;

};


#pragma once

#include "Object.hpp"
#include <vector>
#include <fstream>

class ListOfLessons final
{
public:
	ListOfLessons();
	~ListOfLessons();

	ListOfLessons(const std::vector<StLesson*>& lessons);

	void readFile(const std::string& filename);
	void print() const noexcept;

private:
	std::vector<StLesson*> lessons_;

};
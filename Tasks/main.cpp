#include "ListOfLessons.hpp"
#include "stringProcessing.h"

void test()
{
	StringProcessing handler;
	std::vector<std::string> filenames = {
		"1.txt",
		"2.txt",
		"3.txt",
		"4.txt"
	};

	for (const std::string& filename : filenames)
	{
		ListOfLessons lol;

		std::cout << "\n======== TEST FILE: " << filename << " ==========\n";

		lol.readFile(filename, (Parser*)&handler);
		lol.print();

		std::cout << "================ NEXT ===================\n\n";
	}

	std::cout << "...\n================ Oops! That's all I have! ===================\n";
}

int main(void)
{
	test();
	return 0;
}
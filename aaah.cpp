// kattis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
	std::string ahh_one;
	std::string ahh_two;

	std::getline(std::cin, ahh_one);
	std::getline(std::cin, ahh_two);

	std::cout << (ahh_one.length() >= ahh_two.length() ? "go" : "no") << std::endl;
	return 0;
}
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

int main(int argc, char* argv[])
{
	int first, second;
	std::cin >> first >> second;

	std::string first_string = std::to_string(first);
	std::string second_string = std::to_string(second);

	std::reverse(first_string.begin(), first_string.end());
	std::reverse(second_string.begin(), second_string.end());

	first = std::stoi(first_string);
	second = std::stoi(second_string);

	std::cout << (first > second ? first_string : second_string) << std::endl;
}


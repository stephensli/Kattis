#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>

int main(int argc, char* argv[])
{
	std::string input_value;
	std::getline(std::cin, input_value);

	if (input_value.find("ss") != std::string::npos)
	{
		std::cout << "hiss" << std::endl;
	} else
	{
		std::cout << "no hiss" << std::endl;
	}

	return 0;
}


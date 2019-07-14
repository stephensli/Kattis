#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


int main(int argc, char* argv[])
{
	int base_number;
	std::cin >> base_number;

	long amount = 0;

	for (int i = 0; i < base_number; ++i)
	{
		int input;
		std::cin >> input;

		amount += std::pow(input / 10, input % 10);
	}

	std::cout << amount << std::endl;

	return 0;
}


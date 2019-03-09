#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


int main(int argc, char* argv[])
{
	int days;
	std::cin >> days;

	int amount = 0;

	for (int i = 0; i < days; ++i)
	{
		double value;
		std::cin >> value;

		if (value < 0)  amount += 1;
	}

	std::cout << amount << std::endl;

	return 0;
}


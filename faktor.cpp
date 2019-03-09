#include <iostream>
#include <iterator>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
	double first, second;
	std::cin >> first >> second;

	int amount = 0;

	while (true)
	{
		amount += 1;
		const double total = amount / first;
		if (total == second || std::ceil(total) == second) break;
	}

	std::cout << amount << std::endl;
}


#include <iostream>
#include <string>
#include <iomanip>


int main(int argc, char* argv[])
{
	double seed_cost;
	std::cin >> seed_cost;

	double number_lawns;
	std::cin >> number_lawns;

	double total_cost = 0;

	for (int i = 0; i < number_lawns; ++i)
	{
		double first, second;
		std::cin >> first >> second;

		total_cost += (first * second);
	}

	std::cout << std::setprecision(7);
	std::cout << std::fixed;
	std::cout << total_cost * seed_cost << std::endl;
	return 0;
}


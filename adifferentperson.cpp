// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <limits>

// define the limits of the double object.
typedef std::numeric_limits<double> dbl;

int main(int argc, char* argv[])
{
	std::string input;
	std::getline(std::cin, input);

	// set the precision of cout to be the max limit
	std::cout.precision(dbl::max_digits10);

	while (!input.empty())
	{
		std::istringstream iss(input);
		std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

		const double first = std::stod(results[0]);
		const double second = std::stod(results[1]);

		const double difference = first > second ? first - second : second - first;
		std::cout << difference << std::endl;

		std::getline(std::cin, input);
	}
}

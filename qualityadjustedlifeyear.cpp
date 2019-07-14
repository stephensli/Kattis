#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>

int main(int argc, char* argv[])
{
	std::string amount;
	std::getline(std::cin, amount);

	double total = 0;
	int count = 0;

	std::string input_line;
	std::getline(std::cin, input_line);

	while (!input_line.empty())
	{

		std::istringstream iss(input_line);
		std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

		total += std::stod(results[0]) * std::stod(results[1]);
		count += 1;

		if (count == std::stoi(amount)) break;

		std::getline(std::cin, input_line);
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(3);
	std::cout << total << std::endl;
}


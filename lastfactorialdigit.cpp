#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iomanip>

int fact(int number)
{
	if (number == 1) return number;
	return fact(number - 1) * number;
}

int main(int argc, char* argv[])
{
	int amount;
	std::cin >> amount;

	for (int i = 0; i < amount; ++i)
	{
		int factorial_number;
		std::cin >> factorial_number;

		const int result = fact(factorial_number);
		std::string result_string = std::to_string(result);

		std::cout << result_string[result_string.length() - 1] << std::endl;
	}

	return 0;
}


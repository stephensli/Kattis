#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
	int total_tests;
	std::cin >> total_tests;

	for (auto i = 0; i < total_tests; ++i)
	{
		int one, two, three;
		std::cin >> one >> two >> three;

		auto ssd = 0;

		while (three > 0) {
			ssd += (three % two) * (three % two);
			three /= two;
		}

		std::cout << one << " " << ssd << "\n";
	}
}

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main(int argc, char* argv[])
{
	int test_cases;
	std::cin >> test_cases;

	for (auto i = 0; i < test_cases; ++i)
	{
		double pairs;
		std::cin >> pairs;

		std::vector<double> pair_x;
		std::vector<double> pair_y;

		for (auto j = 0; j < pairs; ++j)
		{
			double one, two;
			std::cin >> one >> two;

			pair_x.push_back(one);
			pair_y.push_back(two);
		}

		double left = 0.0;
		double right = 0.0;

		for (int i = 0; i < pairs; ++i)
		{
			left += pair_x.at(std::fmod(i, pairs)) * pair_y.at(std::fmod(i + 1, pairs));
			right += pair_y.at(std::fmod(i, pairs)) * pair_x.at(std::fmod(i + 1, pairs));
		}

		std::cout << std::abs(((left)-(right)) / 2) << std::endl;
	}

	return 0;
}


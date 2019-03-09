#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
	int first, second, third, fourth;

	int total = 0;
	int value = 0;

	for (int i = 0; i < 5; ++i)
	{
		std::cin >> first >> second >> third >> fourth;
		const auto select_total = first + second + third + fourth;

		if (select_total > total)
		{
			total = select_total;
			value = i + 1;
		}
	}
		std::cout << value << " " << total << std::endl;
}

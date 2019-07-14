#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	int amount_data;
	std::cin >> amount_data;

	while (amount_data != -1)
	{
		auto hours_driven = 0;
		auto total_miles = 0;

		for (auto i = 0; i < amount_data; ++i)
		{
			int first, second;
			std::cin >> first >> second;

			const auto amount_difference = second - hours_driven;
			total_miles += amount_difference * first;

			hours_driven += amount_difference;
		}

		std::cout << total_miles << " miles" << std::endl;
		std::cin >> amount_data;
	}
}

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	int megs_amount;
	std::cin >> megs_amount;

	int months;
	std::cin >> months;

	auto total_used = 0;
	const auto total_allowed = megs_amount * months;

	for (auto i = 0; i < months; ++i)
	{
		int month_used;
		std::cin >> month_used;

		total_used += month_used;
	}

	std::cout << (total_allowed - total_used) + megs_amount << std::endl;
}

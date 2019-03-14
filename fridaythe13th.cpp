#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
	int test_cases;
	std::cin >> test_cases;

	for (auto i = 0; i < test_cases; ++i)
	{
		int days_in_year, months, amount_friday_13 = 0, current_day = 0;
		std::cin >> days_in_year >> months;

		for (auto j = 0; j < months; ++j)
		{
			int days_in_month;
			std::cin >> days_in_month;

			for (auto l = 0; l < days_in_month; ++l)
			{
				if ((current_day) % 7 == 5 && l == 12) amount_friday_13 += 1;
				current_day += 1;
			}
		}

		std::cout << amount_friday_13 << std::endl;
	}
	return 0;
}


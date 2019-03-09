#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
	int first, second;
	std::cin >> first >> second;

	if (second <= 45)
	{
		second = 60 - std::abs(second - 45);
		first = first == 0 ? 23 : first -= 1;
	} else {
		second -= 45;
	}	

	std::cout << first << " " << second;
}

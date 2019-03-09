#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	for (int i = 0; i < 6; ++i)
	{
		int input;
		std::cin >> input;

		if (i <= 1)
		{
			std::cout << 1 - input;
		} else if (i >= 2 && i <= 4)
		{
			std::cout << 2 - input;
		} else
		{
			std::cout << 8 - input;
		}

		std::cout << " ";
	}

	std::cout << std::endl;
}


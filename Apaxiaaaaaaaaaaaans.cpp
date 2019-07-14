#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


int main(int argc, char* argv[])
{
	std::string input_string;
	std::string output_string;

	std::cin >> input_string;

	for (int i = 0; i < input_string.length(); ++i)
	{
		const char starter = input_string[i];

		if (i + 1 < input_string.length())
		{
			const char following = input_string[i + 1];

			if (starter != following)
			{
				output_string += starter;
			}
		} else
		{
			output_string += starter;
		}
	}

	std::cout << output_string << std::endl;

	return 0;
}


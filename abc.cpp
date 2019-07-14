#include  <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::string numbers;
	std::string alpha;

	std::getline(std::cin, numbers);
	std::getline(std::cin, alpha);

	std::string buffer;
	std::stringstream ss(numbers);

	std::vector<int> values;

	while (ss >> buffer)
	{
		values.push_back(std::stoi(buffer));
	}

	std::sort(values.begin(), values.end());

	for (auto value : alpha)
	{
		switch (value)
		{
		case 'A':
			std::cout << values[0] << " ";
			break;
		case 'B':
			std::cout << values[1] << " ";
			break;
		case 'C':
			std::cout << values[2] << " ";
			break;
		}

	}
}

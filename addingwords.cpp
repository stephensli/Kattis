#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iterator>
#include <unordered_map>

bool is_operation(const char value)
{
	return value == '+' || value == '-';
}

bool is_operation(const std::string& value)
{
	return is_operation(value[0]);
}

int main(int argc, char* argv[])
{
	std::unordered_map<std::string, long> definitions;

	std::string input;
	std::getline(std::cin, input);

	while (!input.empty())
	{
		std::istringstream iss(input);
		std::vector<std::string> split_input(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

		if (split_input.at(0) == "clear") definitions.clear();

		if (split_input.at(0) == "def")
		{
			std::string variable = split_input.at(1);
			const long value = std::stol(split_input.at(2));

			auto find_value = definitions.find(variable);

			if (find_value != definitions.end()) find_value->second = value;
			else definitions.insert(std::pair<std::string, long>(variable, value));
		}

		if (split_input.at(0) == "calc")
		{
			long running_total = 0;
			long last_value = 0;

			bool failed = false;
			bool first_number = true;

			auto find = definitions.find(split_input.at(1));
			if (find != definitions.end()) running_total = find->second;
			else failed = true;

			for (int i = 1; i < static_cast<int>(split_input.size()); ++i)
			{
				std::string value = split_input.at(i);
				std::cout << value << " ";

				if (failed && value != "=") continue;
				if (failed && value == "=")
				{
					std::cout << "unknown" << std::endl;
					break;
				}

				if (is_operation(value))
				{
					auto find = definitions.find(split_input.at(i + 1));

					if (find != definitions.end())
					{
						last_value = find->second;

						if (value == "+")
							running_total += last_value;

						if (value == "-")
							running_total -= last_value;
					}
					else
					{
						failed = true;
					}
				}

				if (value == "=")
				{
					std::string running_name;

					for (auto it = definitions.begin(); it != definitions.end(); ++it)
						if (it->second == running_total)
							running_name = it->first;


					if (running_name.empty())
						std::cout << "unknown" << std::endl;
					else
						std::cout << running_name << std::endl;
				}

				if (first_number) first_number = false;
			}
		}

		std::getline(std::cin, input);
	}

	return 0;
}


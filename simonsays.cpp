#include <iostream>
#include <string>

#include <vector>
#include <string>


int main()
{
	std::vector<std::string> results;
	int amount = 0;

	std::cin >> amount;

	for (int i = 0; i <= amount; i++)
	{
		std::string gathered_value;
		std::getline(std::cin, gathered_value);

		if (gathered_value.length() > 10 && gathered_value.substr(0, 10) == "Simon says") {
			std::cout << gathered_value.substr(11) << std::endl;
		}

	}


}
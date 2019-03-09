#include  <iostream>
#include  <string>

int main(int argc, char* argv[])
{
	int amount;
	std::cin >> amount;

	for (int i = 0; i < amount; ++i)
	{
		std::cout << i + 1 <<  " Abracadabra" << std::endl;
	}
}

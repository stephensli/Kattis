#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int number_cases;
	cin >> number_cases;

	for (int i = 0; i < number_cases; ++i)
	{
		int length_of_pole, number_of_ants;
		cin >> length_of_pole >> number_of_ants;

		int smallest = 0;
		int most_mean_ant = 0;

		for (int j = 0; j < number_of_ants; ++j)
		{
			int ant;
			cin >> ant;

			smallest = max(smallest, min(ant, length_of_pole - ant));
			most_mean_ant = max(most_mean_ant, max(ant, length_of_pole - ant));
		}


		std::cout << smallest << " " << most_mean_ant << endl;
	}
}

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	int number_hands;
	char value_of_suit;

	cin >> number_hands;
	cin >> value_of_suit;

	vector<string> card_descriptions;
	
	string line_input;
	getline(cin, line_input);

	map<char, double> mapped_normal;

	mapped_normal['A'] = 11;
	mapped_normal['K'] = 4;
	mapped_normal['Q'] = 3;
	mapped_normal['J'] = 2;
	mapped_normal['T'] = 10;
	mapped_normal['9'] = 0;
	mapped_normal['8'] = 0;
	mapped_normal['7'] = 0;

	map<char, double> mapped_dominant;

	mapped_dominant['A'] = 11;
	mapped_dominant['K'] = 4;
	mapped_dominant['Q'] = 3;
	mapped_dominant['J'] = 20;
	mapped_dominant['T'] = 10;
	mapped_dominant['9'] = 14;
	mapped_dominant['8'] = 0;
	mapped_dominant['7'] = 0;

	double total = 0;

	card_descriptions.reserve(4 * number_hands);

	for (int i = 0; i < 4 * number_hands; ++i)
	{
		getline(cin, line_input);
		card_descriptions.push_back(line_input);
	}

	for (auto card : card_descriptions)
	{
		const char card_value = card[0];
		const char card_face = card[1];

		if (card_face == value_of_suit)
		{
			total += mapped_dominant.at(card_value);
		} else
		{
			total += mapped_normal.at(card_value);
		}
	}

	std::cout << fixed << setprecision(0);
	std::cout << total << endl;
}

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <unordered_map>

using namespace std;

struct by_first_couple
{
	inline bool operator() (const string& first_string, const string& second_string) const
	{
		auto first = string(first_string.begin(), first_string.begin() + 2);
		auto second = string(second_string.begin(), second_string.begin() + 2);

		transform(first.begin(), first.end(), first.begin(), ::tolower);
		transform(second.begin(), second.end(), second.begin(), ::tolower);

		return (first < second);
	}
};

int main(int argc, char* argv[])
{
	auto number_words(0);
	cin >> number_words;

	while (number_words != 0)
	{
		string input_word;
		vector<string> words;

		for (auto i = 0; i < number_words; ++i)
		{
			cin >> input_word;
			words.push_back(input_word);
		}

		// sort the list of strings by the first couple of characters only, if
		// the first two characters are are the sae then the they should keep
		// the same order as per they where inserted.
		sort(words.begin(), words.end(), by_first_couple());

		// output every single word in the current sorted order.
		for (const auto& word : words) cout << word << endl;

		// regather the number of words before reiterating again.
		cin >> number_words;

		// if its not the end then insert a new line.	
		if (number_words != 0) cout << endl;
	}

	return 0;
}


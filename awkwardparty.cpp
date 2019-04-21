#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	long total_numbers;
	cin >> total_numbers;

	map<long, vector<long>> mapped_values;

	for (auto i = 0; i < total_numbers; ++i)
	{
		long number;
		cin >> number;

		if (mapped_values.find(number) != mapped_values.end())
		{
			mapped_values[number].push_back(i + 1);
		}
		else
		{
			mapped_values[number].push_back(i + 1);
		}
	}

	// determine if two people speaking the same language or not if two
	// people speak the same language then we can continue otherwise we know
	// its N awkwardness.
	auto contains_duplicates(false);
	auto largest_gap = total_numbers;

	for (const auto& input : mapped_values) {
		if (input.second.size() > 1) contains_duplicates = true;

		for (auto j = 0; j < input.second.size(); ++j)
		{
			const auto first_pos = input.second.at(j);
			const auto second_pos = input.second.at(input.second.size() - 1);

			if (first_pos == second_pos) continue;
			largest_gap = min(largest_gap, long(second_pos - first_pos));
		}
	}

	if (!contains_duplicates) cout << total_numbers << endl;
	else cout << largest_gap << endl;

	return 0;
}


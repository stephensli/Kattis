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

tuple<long, long> get_weakest(const vector<long>& monsters)
{
	long weakest(-1), position(-1);

	for (auto i = 0; i < monsters.size(); ++i)
	{
		const auto monster = monsters.at(i);

		if (weakest > monster || weakest == -1)
		{
			weakest = monster;
			position = i;
		}
	}

	return { position, weakest };
}

int main(int argc, char* argv[])
{
	long total_numbers;
	cin >> total_numbers;

	for (auto i = 0; i < total_numbers; ++i)
	{
		long number_god, number_mecca;
		cin >> number_god >> number_mecca;

		vector<long> gods, meccas;

		for (auto j = 0; j < number_god; ++j)
		{
			long god;
			cin >> god;

			gods.push_back(god);
		}

		for (auto j = 0; j < number_mecca; ++j)
		{
			long mecca;
			cin >> mecca;

			meccas.push_back(mecca);
		}

		sort(gods.begin(), gods.end());
		sort(meccas.begin(), meccas.end());

		auto god_pos(0), mecca_pos(0);
		const int god_size(gods.size()), mecca_size(meccas.size());

		while (god_pos < god_size && mecca_pos < mecca_size)
		{
			const auto god_weakest = gods.at(god_pos);
			const auto mecca_weakest = meccas.at(mecca_pos);

			if (god_weakest == mecca_weakest || mecca_weakest < god_weakest)
			{
				mecca_pos += 1;
			}
			else if (god_weakest < mecca_weakest)
			{
				god_pos += 1;
			}
		}

		const auto print_value = god_pos < god_size ? "Godzilla" : "MechaGodzilla";
		cout << print_value << endl;
	}

	return 0;
}


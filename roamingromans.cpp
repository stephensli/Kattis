// CodeJam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void)
{
	double input_value;
	cin >> input_value;

	const double output_value = input_value * 1000.0 * 5280.0 / 4854.0;

	cout << fixed << setprecision(0);
	cout << round(output_value) << endl;

	return 0;
}

// kattis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;



void recipe(const int ingredients, double scale)
{
	vector<string> names;
	vector<double> percentages;

	double main_int_gram_scale = 0;

	for (int i = 0; i < ingredients; ++i)
	{
		double grams, percentage;
		string name;

		cin >> name >> grams >> percentage;

		if (percentage == 100.0) main_int_gram_scale = grams * scale;

		names.push_back(name);
		percentages.push_back(percentage /= 100);
	}

	cout << fixed;
	cout << setprecision(1);

	for (int i = 0; i < ingredients; ++i)
	{
		cout << names.at(i) << " " << main_int_gram_scale * percentages.at(i) << endl;
	}
}


int main()
{
	int num_problems;
	cin >> num_problems;
#
	for (int i = 0; i < num_problems; ++i)
	{
		int num_ingredients;
		double num_portions, num_required;
		cin >> num_ingredients >> num_portions >> num_required;

		cout << "Recipe # " << i+1 << endl;
		recipe(num_ingredients, num_required / num_portions);
		cout << "----------------------------------------" << endl;
	}
}

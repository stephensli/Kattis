#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	long number_of_iterations;
	cin >> number_of_iterations;

	const long power_result = pow(2, number_of_iterations) + 1;

	cout << fixed;
	std::cout << setprecision(0);
	std::cout << pow(power_result, 2) << endl;
}

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	double number_bats;
	double output_value = 0;
    
	cin >> number_bats;
    
	double divider = number_bats;
    
	for (int i = 0; i < number_bats; ++i)
	{
		double input_value;
		cin >> input_value;
        
		if (input_value == -1) divider -= 1;
		else output_value += input_value;
	}
    
	double divider_value = output_value / divider;
    
	std::cout << setprecision(16);
	std::cout << divider_value << endl;
}

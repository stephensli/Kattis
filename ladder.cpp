#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


int main(int argc, char* argv[])
{
	double height, degrees;
	std::cin >> height >> degrees;

	// calculate the hypotenuse of the distance of the triangle using sin radius
	// we can calculate the radis with the height * pi / 180

	const double radius = degrees * (M_PI / 180.0);
	const long distance = std::ceil(height / std::sin(radius));

	std::cout << distance << std::endl;

	return 0;
}


// Twitch.Kattis.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

int main() {
  long number_swords_broken(0);
  std::cin >> number_swords_broken;

  std::string input_tblr;
  std::getline(std::cin, input_tblr);

  long tb(0), lr(0);

  for (auto i = 0; i < number_swords_broken; ++i) {
    std::getline(std::cin, input_tblr);

    if (input_tblr.at(0) == '0') tb += 1;
    if (input_tblr.at(1) == '0') tb += 1;
    if (input_tblr.at(2) == '0') lr += 1;
    if (input_tblr.at(3) == '0') lr += 1;
  }

  long number_swords = 0;

  while (tb >= 2 && lr >= 2) {
    tb -= 2;
    lr -= 2;

    number_swords += 1;
  }

  std::cout << number_swords << " " << tb << " " << lr << std::endl;
}

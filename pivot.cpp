// Twitch.Kattis.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  // the total number of elements possible.
  long number_distinct_integers(0);
  std::cin >> number_distinct_integers;

  // a list of distinct elements that are occuring, list just ensures no
  // duplicates.
  std::set<long> distinct_elements;

  long next_number(0);
  long largest_number(0);

  std::cin >> next_number;
  number_distinct_integers -= 1;

  largest_number = next_number;
  distinct_elements.insert(largest_number);

  while (number_distinct_integers--) {
    std::cin >> next_number;

    // if the current number is larger than our current largest, then this is a
    // possible pivot point, otherwise we need to remove the possible canidates
    // and remove any larger than our current largest.
    if (next_number > largest_number) {
      distinct_elements.insert(next_number);
      largest_number = next_number;
      continue;
    }

    auto start_elements = distinct_elements.begin();

    while (start_elements != distinct_elements.end()) {
      // make sure to relocate our position in the array since it has
      // changed after erasing largetr number.
      if (*start_elements > next_number)
        start_elements = distinct_elements.erase(start_elements);
      else
        ++start_elements;
    }
  }

  std::cout << distinct_elements.size() << std::endl;
}

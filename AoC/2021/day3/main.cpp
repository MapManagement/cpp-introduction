#include "../helpers/file_helper.h"
#include <bitset>
#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_input_vector() {
  string filepath = "input";
  vector<int> input_vector = read_file_as_int_vector(filepath, 2);

  return input_vector;
}

int get_max_exponent(vector<int> elements) {
  int max = elements[0];
  for (int i = 1; i < elements.size(); i++) {
    if (elements[i] > max)
      max = elements[i];
  }

  return ceil(log2(max));
}

int invert_bits(int number) {
  int x = log2(number) + 1;

  for (int i = 0; i < x; i++)
    number = (number ^ (1 << i));

  return number;
}

int calculate_power_consumption() {
  vector<int> input = get_input_vector();
  int digit_length = get_max_exponent(input);

  int gamma_rate = 0;
  int number_ones = 0;
  int number_zeros = 0;

  for (int j = 0; j < digit_length; j++) {
    number_ones = 0;
    number_zeros = 0;

    for (int i = 0; i < input.size(); i++) {
      int pattern = pow(2, digit_length - j - 1);
      int match = input[i] & pattern;

      if (match == pattern)
        number_ones++;
      else {
        number_zeros++;
      }

      if ((number_ones > input.size() / 2)) {
        gamma_rate += pow(2, digit_length - j - 1);
        break;
      }

      else if ((number_zeros > input.size() / 2))
        break;
    }
  }

  cout << std::bitset<5>(gamma_rate);
  cout << endl;

  cout << std::bitset<5>(invert_bits(gamma_rate));
  cout << endl;

  return gamma_rate * invert_bits(gamma_rate);
}

void first_task() {
  int power_consumption = calculate_power_consumption();
  cout << power_consumption;
}

void second_task() {}

int main() {
  first_task();
  cout << endl;
  second_task();
}

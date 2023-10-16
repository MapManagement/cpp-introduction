#include "../helpers/file_helper.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

vector<int> input_into_int_vector() {
  string filepath = "input";
  vector<int> depth_vector = read_file_as_int_vector(filepath);

  return depth_vector;
}

int count_depth_increasement(vector<int> depths) {
  int counter = 0;

  for (int i = 1; i < depths.size(); i++) {
    if (depths[i] < depths[i - 1])
      continue;

    counter++;
  }

  return counter;
}

int count_window_depth_increasement(vector<int> depths) {
  int counter = 0;
  int prev_window = depths[0] + depths[1] + depths[2];
  int curr_window = 0;

  for (int i = 0; i < depths.size()-2; i++) {
    for (int j = 0; j < 3; j++) {
      curr_window += depths[i + j];
    }

    if (curr_window > prev_window)
      counter++;

    prev_window = curr_window;
    curr_window = 0;
  }

  return counter;
}

void first_task() {
  vector<int> depths = input_into_int_vector();

  int counter = count_depth_increasement(depths);

  cout << "First task: " + to_string(counter);
}

void second_task() {
  vector<int> depths = input_into_int_vector();
  int counter = count_window_depth_increasement(depths);

  cout << "Second task: " + to_string(counter);
}

int main() {
  first_task();
  cout << endl;
  second_task();
}

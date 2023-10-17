#include "../helpers/file_helper.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

enum Direction { Forward, Down, Up, Undefined };

struct Movement {
  Direction direction;
  int distance;
};

vector<string> get_input_vector() {
  string filepath = "input";
  vector<string> input_vector = read_file_as_string_vector(filepath);

  return input_vector;
}

Direction get_direction_from_string(string direction) {
  if (direction == "forward")
    return Forward;
  else if (direction == "up")
    return Up;
  else if (direction == "down")
    return Down;
  else
    return Undefined;
}

vector<Movement> define_movements(vector<string> input) {
  vector<Movement> movements = {};

  for (int i = 0; i < input.size(); i++) {
    Movement movement;
    string line = input[i];
    string string_direction = line.substr(0, line.find(" "));
    movement.direction = get_direction_from_string(string_direction);

    string string_distance = line.substr(line.find(" ") + 1, line.size() - 1);
    movement.distance = stoi(string_distance);

    movements.push_back(movement);
  }

  return movements;
}

int calculate_multiplier(vector<Movement> movements) {
  int depth = 0;
  int horizontal_pos = 0;

  for (int i = 0; i < movements.size(); i++) {
    Movement m = movements[i];

    if (m.direction == Forward)
      horizontal_pos += m.distance;
    else if (m.direction == Up)
      depth -= m.distance;
    else if (m.direction == Down)
      depth += m.distance;
    else
      continue;
  }

  return depth * horizontal_pos;
}

int calculate_multiplier_with_aim(vector<Movement> movements) {
  int depth = 0;
  int horizontal_pos = 0;
  int aim = 0;

  for (int i = 0; i < movements.size(); i++) {
    Movement m = movements[i];

    if (m.direction == Forward) {
      horizontal_pos += m.distance;
      depth += aim * m.distance;
    } else if (m.direction == Up)
      aim -= m.distance;
    else if (m.direction == Down)
      aim += m.distance;
    else
      continue;
  }

  return depth * horizontal_pos;
}

void first_task() {
  vector<string> input_vector = get_input_vector();
  vector<Movement> movements = define_movements(input_vector);
  int result = calculate_multiplier(movements);

  cout << "First task: " + to_string(result);
}

void second_task() {
  vector<string> input_vector = get_input_vector();
  vector<Movement> movements = define_movements(input_vector);
  int result = calculate_multiplier_with_aim(movements);

  cout << "Second task: " + to_string(result);
}

int main() {
  first_task();
  cout << endl;
  second_task();
}

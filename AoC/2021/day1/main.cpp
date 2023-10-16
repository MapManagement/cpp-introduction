#include "../helpers/file_helper.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  string filepath = "input";

  string input = read_file(filepath);

  cout << input;
}

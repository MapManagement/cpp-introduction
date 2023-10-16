#include "file_helper.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string read_file_as_string(string filepath) {
  string line;
  string filetext = "";

  ifstream TargetFile(filepath);

  if (!TargetFile) {
    cout << "File has not been found";
  }

  while (getline(TargetFile, line)) {
    filetext = filetext + line + '\n';
  }

  TargetFile.close();

  return filetext;
}

vector<int> read_file_as_int_vector(string filepath) {
  string line;
  string filetext = "";

  ifstream TargetFile(filepath);

  if (!TargetFile) {
    cout << "File has not been found";
  }

  vector<int> input_vector = {};

  while (getline(TargetFile, line)) {
    /*int line_break_pos = line.find("\n");
    cout << line_break_pos;

    if (line_break_pos == string::npos)
      continue;

    line.erase(line_break_pos, line_break_pos + 2);*/

    int depth = stoi(line);
    input_vector.push_back(depth);
  }

  TargetFile.close();

  return input_vector;
}

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
    int value = stoi(line);
    input_vector.push_back(value);
  }

  TargetFile.close();

  return input_vector;
}

vector<string> read_file_as_string_vector(string filepath) {
  string line;
  string filetext = "";

  ifstream TargetFile(filepath);

  if (!TargetFile) {
    cout << "File has not been found";
  }

  vector<string> input_vector = {};

  while (getline(TargetFile, line)) {
    input_vector.push_back(line);
  }

  TargetFile.close();

  return input_vector;
}

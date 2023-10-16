#include "file_helper.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string read_file(string filepath) {
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

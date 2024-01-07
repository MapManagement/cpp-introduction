#include "matrix.hh"
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  // a)
  std::cout << "0-Matrix" << std::endl;
  Matrix<int, 3, 2> m;
  m.print();

  std::cout << "Gefüllte Matrix" << std::endl;
  m.get(0, 0) = 0;
  m.get(0, 1) = 1;
  m.get(0, 2) = 2;
  m.get(1, 0) = 3;
  m.get(1, 1) = 4;
  m.get(1, 2) = 5;

  m.print();

  std::cout << "Einzelne Zellen" << std::endl;

  std::cout << m.get(0, 0) << std::endl;
  std::cout << m.get(1, 2) << std::endl;

  // b)
  std::cout << "Transponierte Matrix" << std::endl;
  m.transpose().print();

  // c)
  std::cout << "Addition" << std::endl;
  Matrix<int, 3, 2> n;
  n.get(0, 0) = 5;
  n.get(0, 1) = 4;
  n.get(0, 2) = 3;
  n.get(1, 0) = 2;
  n.get(1, 1) = 1;
  n.get(1, 2) = 0;

  m.add(n).print();

  std::cout << "Subtratkion" << std::endl;
  m.subtract(n).print();

  // e)
  std::cout << "Matrix aus Vector" << std::endl;
  std::vector<std::vector<int>> vec{{10, 11, 12}, {13, 14, 15}};
  Matrix<int, 3, 2> o(vec);
  o.print();

  std::cout << "Matrix aus Array" << std::endl;
  std::array<std::array<float, 3>, 2> arr{
      {{1.1f, 1.2f, 1.3f}, {1.4f, 1.5f, 1.6f}}};
  Matrix<float, 3, 2> p(arr);
  p.print();

  return 0;
}

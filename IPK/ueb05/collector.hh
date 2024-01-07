#include <string>
#include <vector>
template <typename T> class Collector {
  std::vector<T> vec;

public:
  Collector(T firstItem, T secondItem) : vec() {
    vec.push_back(firstItem);
    vec.push_back(secondItem);
  }

  void add(T item) { vec.push_back(item); }

  std::string digest() {
    std::string output = "";

    for (int i = 0; i < vec.size(); ++i) {
      output += std::to_string(vec[i]);

      if (i != vec.size() - 1) {
        output.append(", ");
      }
    }

    return output;
  }
};

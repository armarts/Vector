#include <iostream>
#include "vector.h"

int main() {
  try {
  Vector<int> v;
  v.resize(10, -1);
  //if (v < g)
  //  std::cout << "help" << std::endl;
  for (std::size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  //std::cout << "\n" << g.size() << " " << g.capacity() << "\n";
  } catch (Exception &ex) {
    std::cerr << ex.what();
  }
  return 0;
}

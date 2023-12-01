#include <iostream>
#include <vector>

#include "src/Algorithm/QuickSort.cpp"

int main() {
  std::vector<int> data{1, 6, 7, 3};
//  quick_sort_r_pivot(data, 0, data.size() - 1);
  quick_sort(data);
  for (int num: data) {
    std::cout << num << std::endl;
  }
  return 0;
}
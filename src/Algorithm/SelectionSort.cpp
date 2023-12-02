/*
 选择排序
  （有序区，无序区）。在无序区里找一个最小的元素跟在有序区的后面。

 选择排序思路：
  1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
  2. 从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
  3. 以此类推，直到所有元素均排序完毕

 */

#include <vector>

void selection_sort(std::vector<int> &arr) {
  size_t len = arr.size();
  int min;
  for (int i = 0; i < len - 1; ++i) {
    min = i;
    for (int j = i + 1; j < len; ++j) {
      if (arr[j] < arr[i]) {
        min = j;
      }
    }
    if (i != min) {
      std::swap(arr[i], arr[min]);
    }
  }
}
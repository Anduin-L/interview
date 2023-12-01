/*
  快速排序的基本思想：

  选择一个基准元素（Pivot）： 从待排序数组中选择一个元素作为基准（通常选择第一个元素）。

  划分阶段（Partition）：将数组重新排列，使得比基准小的元素位于基准之前，比基准大的元素位于基准之后。基准元素的最终位置就是其在排序后的位置。

  递归操作： 递归地对基准左右两侧的子数组进行快速排序。

  快速排序的步骤：

  选择基准元素：
  选择数组中的一个元素作为基准元素。可以选择第一个元素、最后一个元素、中间元素或者随机选择。

  划分数组：
  将数组中比基准元素小的元素移到基准元素的左边，比基准元素大的元素移到基准元素的右边。这一过程称为划分（Partition）。

  递归排序：
  递归地对基准元素左右两侧的子数组进行快速排序。

  合并结果：
  由于划分操作使得基准元素的最终位置确定，因此当子数组排序完成后，整个数组就被分成了基准元素左右两个部分，左边的部分都小于基准元素，右边的部分都大于基准元素。

  时间复杂度：
  最优时间复杂度：
  在最优情况下，即每次划分都能均匀地将数组分成两部分，快速排序的时间复杂度为 O(n log n)。

  最差时间复杂度：
  在最差情况下，即每次划分都只能将数组分成一个元素和其他元素两部分，快速排序的时间复杂度为 O(n^2)。最差情况通常出现在已经有序的数组中，或者在选择基准元素时不幸选择了最大或最小的元素。

  平均时间复杂度：
  在平均情况下，快速排序的时间复杂度为 O(n log n)。这是通过期望值分析得出的，平均情况下，每个元素都有机会成为基准元素，且划分过程能够均匀地将数组分割。

  空间复杂度：
  快速排序是一种原地排序算法，其空间复杂度为 O(log n)。这是由于快速排序是通过不断地对数组进行原地划分实现的，而递归调用的栈深度最多为 log n。

  稳定性：
  快速排序是一种不稳定的排序算法，因为在划分的过程中相同元素的相对位置可能会发生变化。

  总结：
  最优情况： O(n log n)
  最差情况： O(n^2)
  平均情况： O(n log n)
  空间复杂度： O(log n)
  在实际应用中，快速排序通常是一种性能优秀的排序算法，尤其在大数据集合的排序中表现良好。为了减小最差情况的发生概率，通常采用一些优化策略，如随机选择基准元素、三数取中法等。
 */

#include <vector>
#include <iostream>
#include <stack>
#include <random>

// 选择最后一个元素作为基准
void quick_sort_r_pivot(std::vector<int> &arr, int l, int r) {
  if (l >= r) return;

  int pivot = arr[r];
  // 基准值应该在的位置
  int pos = l;

  for (int j = l; j < r; ++j) {
    if (arr[j] <= pivot) {
      std::swap(arr[pos], arr[j]);
      ++pos;
    }
  }

  std::swap(arr[r], arr[pos]);

  quick_sort_r_pivot(arr, l, pos - 1);
  quick_sort_r_pivot(arr, pos + 1, r);
}

// 选择第一个元素作为基准
void quick_sort_l_pivot(std::vector<int> &arr, int l, int r) {
  if (l >= r) return;
  int pivot = arr[l];
  // 基准值应该在的位置
  int pos = l;

  for (int i = l + 1; i <= r; ++i) {
    if (arr[i] <= pivot) {
      ++pos;
      std::swap(arr[i], arr[pos]);
    }
  }
  std::swap(arr[pos], arr[l]);

  quick_sort_l_pivot(arr, l, pos - 1);
  quick_sort_l_pivot(arr, pos + 1, r);
}

// 迭代实现
void quick_sort(std::vector<int>& arr) {
  std::stack<std::pair<int, int>> stk;
  size_t len = arr.size();
  stk.emplace(0, len - 1);

  while (!stk.empty()) {
    std::pair<int, int> current = stk.top();
    stk.pop();

    int l = current.first;
    int r = current.second;

    if (l >= r) continue;

    int pivot = arr[r];
    int pos = l;

    for (int i = l; i < r; ++i) {
      if(arr[i] <= pivot) {
        std::swap(arr[i], arr[pos]);
        ++pos;
      }
    }

    std::swap(arr[pos], arr[r]);

    stk.emplace(l, pos - 1);
    stk.emplace(pos+1, r);
  }
}

// 随机选取基准值
int getRandomPivotIndex(int low, int high) {
  std::random_device rd;  // 用于获得真实随机数种子
  std::default_random_engine gen(rd());
  std::uniform_int_distribution<int> dist(low, high);

  return dist(gen);
}

int partition(std::vector<int>& arr, int low, int high) {
  // 随机选择基准值
  int pivotIndex = getRandomPivotIndex(low, high);
  std::swap(arr[pivotIndex], arr[high]);

  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; ++j) {
    if (arr[j] <= pivot) {
      std::swap(arr[i], arr[j]);
      ++i;
    }
  }

  std::swap(arr[i + 1], arr[high]);
  return i + 1;
}
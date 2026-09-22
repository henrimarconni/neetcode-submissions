#include <vector>

class Solution {
public:
  int get(const std::vector<std::vector<int>> &matrix, int i) {
    int cols = matrix[0].size();
    return matrix[i / cols][i % cols];
  }
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
      return false;
    int len = matrix.size() * matrix[0].size();
    int start = 0;
    int end = len - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      int val = get(matrix, mid);

      if (val < target)
        start = mid + 1;
      else if (val > target)
        end = mid - 1;
      else
        return true;
    }

    return false;
  }
};

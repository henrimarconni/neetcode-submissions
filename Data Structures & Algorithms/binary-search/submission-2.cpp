#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int i = 0;

    while (start <= end) {
      int mid = start + (end - start) / 2;

      if (nums[mid] <= target) {
        i = mid;
        start = mid + 1;
      } else
        end = mid - 1;
    }

    if (nums[i] == target)
      return i;

    return -1;
  }
};

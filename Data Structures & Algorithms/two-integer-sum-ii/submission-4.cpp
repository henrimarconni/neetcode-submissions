#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;

    while (true) {
      if (nums[i] + nums[j] < target)
        i++;
      else if (nums[i] + nums[j] > target)
        j--;
      else
        return {i + 1, j + 1};
    }
  }
};

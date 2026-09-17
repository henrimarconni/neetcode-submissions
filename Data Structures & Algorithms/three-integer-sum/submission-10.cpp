#include <algorithm>
#include <vector>

/*
  -2 -1 0 1 2 6 9
*/

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res{};
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int k = nums.size() - 1;
      int j = i + 1;

      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      while (j < k) {
        int left = nums[j];
        int right = nums[k];

        if (left + right < -nums[i])
          j++;
        else if (left + right > -nums[i])
          k--;
        else {
          res.push_back({nums[i], left, right});

          // IMP
          while (j < k && nums[j] == nums[j + 1])
            j++;
          while (j < k && nums[k] == nums[k - 1])
            k--;

          j++;
          k--;
        }
      }
    }

    return res;
  }
};

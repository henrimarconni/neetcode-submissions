#include <algorithm>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    std::sort(nums.begin(), nums.end());

    int res = 1;
    int buf = 1;

    for (size_t i = 0; i < nums.size(); i++) {
      if (i < nums.size() - 1 && nums[i] == nums[i + 1])
        continue;
      else if (i < nums.size() - 1 && nums[i] + 1 == nums[i + 1])
        buf++;
      else if (buf > res) {
        res = buf;
        buf = 1;
      } else
        buf = 1;
    }

    return res;
  }
};

#include <cassert>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    // here value is the (index in the vector + 1)

    std::unordered_map<int, int> map{0};
    for (int i = 0; i < nums.size(); i++) {
      map[target - nums[i]] = i + 1;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (map[nums[i]] != 0 && map[nums[i]] != i + 1) {
        std::vector<int> res{};
        res.push_back(i);
        res.push_back(map[nums[i]] - 1);
        return res;
      }
    }

    assert(false && "UNREACHABLE");
  }
};

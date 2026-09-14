#include <cassert>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map{0};

    for (int i = 0; int n : nums) {
      if (map.find(n) != map.end())
        return {map.at(n), i};

      map[target - n] = i;
      i++;
    }

    assert(false && "UNREACHABLE");
  }
};


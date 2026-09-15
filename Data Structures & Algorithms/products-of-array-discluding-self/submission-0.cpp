#include <vector>
class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int prod = 1;
    int zero_count = 0;
    for (int n : nums) {
      if (n != 0)
        prod *= n;
      else
        zero_count++;
    }

    std::vector<int> res{};

    for (int n : nums) {
      if (zero_count > 0 && n != 0)
        res.push_back(0);
      else if (zero_count > 1)
        res.push_back(0);
      else if (n == 0)
        res.push_back(prod);
      else
        res.push_back(prod / n);
    }

    return res;
  }
};

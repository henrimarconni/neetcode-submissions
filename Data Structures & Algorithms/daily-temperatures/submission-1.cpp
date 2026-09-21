#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    std::stack<int> stack;
    std::vector<int> res{};
    res.resize(temperatures.size());
    int prev = 0;
    for (int i = 0; int t : temperatures) {
      if (t > prev) {
        while (!stack.empty() && t > temperatures[stack.top()]) {
          int prev_id = stack.top();
          res[prev_id] = (i - prev_id);
          stack.pop();
        }
      }
      stack.push(i);

      prev = t;
      i++;
    }
    return res;
  }
};

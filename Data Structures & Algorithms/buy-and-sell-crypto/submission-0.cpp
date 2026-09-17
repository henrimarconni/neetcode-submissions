#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.empty())
      return 0;
    
    int profit = 0;
    int min = prices[0];

    for (int sell : prices) {
      if (min > sell)
        min = sell;
      int curr_profit = sell - min;
      if (curr_profit > profit)
        profit = curr_profit;
    }
    
    return profit;
  }
};

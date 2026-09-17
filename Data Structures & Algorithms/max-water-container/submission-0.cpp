#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &heights) {
    int i = 0;
    int j = heights.size() - 1;
    
    int res = 0;

    while (i < j) {
      int h = heights[i] < heights[j] ? heights[i] : heights[j];

      int area = h * (j - i);
      if (area > res)
        res = area;

      if (heights[i] > heights[j])
        j--;
      else
        i++;
    }

    return res;
  }
};


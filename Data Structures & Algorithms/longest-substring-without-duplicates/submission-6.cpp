#include <string>
using string = std::string;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    int len = 0;
    int i = 0;
    bool map[256]{};

    for (; i < s.size(); i++) {
      if (map[s[i]]) {
        if (len < i - start)
          len = i - start;
        while (map[s[i]]) {
          map[s[start]] = false;
          start++;
        }
      }
      map[s[i]] = true;
    }
    if (i - start > len)
      len = i - start;

    return len;
  }
};

#include <algorithm>
#include <string>
using string = std::string;

#define I(x) (x - 'A')

class Solution {
public:
  int characterReplacement(string s, int k) {
    int start = 0;
    int len = 0;
    int max_freq = 0;
    int freq['Z' - 'A' + 1]{};

    for (int i = 0; i < s.length(); i++) {
      freq[I(s[i])]++;
      max_freq = std::max(max_freq, freq[I(s[i])]);

      if ((i - start + 1) > k + max_freq) {
        freq[I(s[start])]--;
        start++;
      }

      len = std::max(len, i - start + 1);
    }

    return len;
  }
};

#include <cstring>
#include <string>

using string = std::string;

class Solution {
public:
  bool isAnagram(string s, string t) {
    char chars[256]{0};
    char chars1[256]{0};

    for (char c : s) {
      chars[c] += 1;
    }
    for (char c : t) {
      chars1[c] += 1;
    }

    return memcmp(chars, chars1, sizeof(char) * 256) == 0;
  }
};

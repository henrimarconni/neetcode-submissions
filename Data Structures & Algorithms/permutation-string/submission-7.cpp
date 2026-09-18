#include <cstring>
#include <string>
using string = std::string;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 > len2) return false;

    int freq1[26];
    int freq2[26];

    // first window
    for (int i = 0; i < len1; i++) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }

    if (memcmp(freq1, freq2, sizeof(int) * 26) == 0)
      return true;

    for (int i = len1; i < len2; i++) {
      freq2[s2[i] - 'a']++; // add entering character
      freq2[s2[i - len1] - 'a']--; // remove leaving character
      if (memcmp(freq1, freq2, sizeof(int) * 26) == 0)
        return true;
    }
    
    return false;
  }
};

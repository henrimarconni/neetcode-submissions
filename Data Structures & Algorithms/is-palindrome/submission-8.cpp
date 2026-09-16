#include <cstdio>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string normalised{};

    for (char ch : s) {
      if (!isalnum(ch))
        continue;

      if (ch >= '0' && ch <= '9') {
        normalised.push_back(ch);
        continue;
      }

      ch = ch >= 'A' && ch <= 'Z' ? ch + 32 : ch;
      normalised.push_back(ch);
    }

    if (normalised.size() == 0)
      return true;

    int i = 0;
    int j = normalised.size() - 1;

    std::cout << normalised << std::endl;

    while (i != normalised.size()) {
      if (normalised[i] != normalised[j])
        return false;

      printf("%d:%d\n", i, j);

      i++;
      j--;
    }

    return true;
  }
};

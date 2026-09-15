#include <string>
#include <vector>

class Solution {
public:
  std::string encode(std::vector<std::string> strs) {
    std::string enc = {};
    for (std::string& str : strs) {
      enc.append(str);
      enc.append("-|-");
    }

    return enc;
  }

  std::vector<std::string> decode(std::string s) {
    std::vector<std::string> res{};
    std::string buf{};

    for (int i = 0; i < s.size(); i++) {
      if (i < s.size() + 2 && s[i] == '-' && s[i+1] == '|' && s[i+2] == '-') {
        res.push_back(buf);
        buf.clear();
        i += 2;
      }
      else
        buf.push_back(s[i]);
    }

    return res;
  }
};

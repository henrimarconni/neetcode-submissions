#include <cstdint>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

using string = std::string;

class Solution {
public:
  std::vector<std::vector<string>> groupAnagrams(std::vector<string> &strs) {
    std::unordered_map<string, std::vector<string>> map;
    for (string& str : strs) {
      map[hash(str)].push_back(str);
    }

    std::vector<std::vector<std::string>> values;
    values.reserve(map.size());
    
    for (auto const& [_, value] : map) {
        values.push_back(value);
    }

    return values;
  }

    
  string hash(string& str) {
    string hash_payload(26, '\0');
    for (char ch : str) {
      hash_payload[ch - 'a'] += 1;
    }
    return hash_payload;
  }
};
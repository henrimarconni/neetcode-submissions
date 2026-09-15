#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> freqs;
    for (int num : nums) {
      freqs[num]++;
    }

    // Bucket sort: bucket[i] contains numbers with frequency i
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (auto const &[num, count] : freqs) {
      buckets[count].push_back(num);
    }

    std::vector<int> x;
    for (int i = buckets.size() - 1; i >= 0 && x.size() < k; --i) {
      for (int num : buckets[i]) {
        x.push_back(num);
        if (x.size() == k)
          break;
      }
    }

    return x;
  }
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map = {};
        for (auto i : nums) {
            map[i] = true;
        }
        return map.size() != nums.size();
    }
};
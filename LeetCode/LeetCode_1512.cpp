class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto item : nums)
            dict[item]++;
        int result = 0;
        for (auto item : dict)
            result += item.second * (item.second - 1) / 2;
        return result;
    }
};
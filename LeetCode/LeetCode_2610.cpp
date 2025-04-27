class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, unordered_set<int>> dict;
        for (int i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < INT_MAX; j++) {
                if (dict[j].find(nums[i]) == dict[j].end()) {
                    dict[j].insert(nums[i]);
                    break;
                }
            }
        }
        vector<vector<int>> result(dict.size());
        int level = 0;
        for (auto item : dict) {
            for (auto inner_item : item.second)
                result[level].push_back(inner_item);
            level++;
        }
        return result;
    }
};
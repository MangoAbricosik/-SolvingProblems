class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> dict;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                dict.insert(nums[i]);
        }
        return dict.size();
    }
};
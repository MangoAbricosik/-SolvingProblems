class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i]);
        }
        prefix.erase(prefix.begin());
        return prefix;
    }
};

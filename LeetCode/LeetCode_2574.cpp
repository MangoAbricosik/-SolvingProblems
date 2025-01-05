class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> prefix = { 0 };
        vector<int> suffix = { 0 };
        for (int i = 0; i < nums.size() - 1; i++) {
            prefix.push_back(nums[i] + prefix[i]);
        }
        for (int i = nums.size() - 1, j = 0; i != 0; i--) {
            suffix.push_back(nums[i] + suffix[j++]);
        }
        reverse(suffix.begin(), suffix.end());

        vector<int> result;
        for (size_t i = 0; i < prefix.size(); i++) {
            result.push_back(abs(prefix[i] - suffix[i]));
        }

        return result;
    }
};
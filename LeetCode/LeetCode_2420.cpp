class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1])
                prefix[i] = (prefix[i - 1] + 1);
        }

        vector<int> suffix(nums.size(), 1);
        for (int i = nums.size() - 2; i > -1; i--) {
            if (nums[i] <= nums[i + 1])
                suffix[i] = suffix[i + 1] + 1;
        }

        vector<int> result;
        for (size_t i = k; i < nums.size() - k; i++) {
            if (prefix[i - 1] >= k && suffix[i + 1] >= k)
                result.push_back(i);
        }
        return result;
    }
};
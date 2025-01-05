class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix = { 0 };
        vector<int> suffix = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i]);
        }
        for (int i = nums.size() - 1, j = 0; i != -1; i--) {
            suffix.push_back(nums[i] + suffix[j++]);
        }

        prefix.erase(prefix.begin());
        suffix.erase(suffix.begin());
        reverse(suffix.begin(), suffix.end());
        for (size_t i = 0; i < prefix.size(); i++) {
            if (prefix[i] == suffix[i])
                return i;
        }
        return -1;
    }
};
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int result, last = *max_element(nums.begin(), nums.end());
        result = last;
        for (size_t i = 1; i < k; i++) {
            result += last = last + 1;
        }
        return result;
    }
};
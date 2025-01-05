class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = 0, l = 0, r = nums.size() - 1;
        for (; l < r; l++, r--) {
            max = std::max(nums[l] + nums[r], max);
        }
        return max;
    }
};
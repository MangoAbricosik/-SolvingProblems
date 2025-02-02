class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];
        size_t i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                prefixSum += nums[i];
            else
                break;
        }
        i--;
        sort(nums.begin(), nums.end());
        for (; i < nums.size(); i++) {
            if (prefixSum == nums[i])
                prefixSum++;
        }
        return prefixSum;
    }
};
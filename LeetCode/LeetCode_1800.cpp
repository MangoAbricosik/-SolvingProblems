class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int current, total;

        current = total = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                current += nums[i];
            else
                current = nums[i];
            total = max(total, current);
        }
        return total;
    }
};
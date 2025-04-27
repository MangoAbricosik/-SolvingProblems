class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxCounter = 1, downCounter = 1, upCounter = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                upCounter++;
            else
                upCounter = 1;

            if (nums[i] < nums[i - 1])
                downCounter++;
            else
                downCounter = 1;

            maxCounter = max(upCounter, max(downCounter, maxCounter));
        }
        return maxCounter;
    }
};
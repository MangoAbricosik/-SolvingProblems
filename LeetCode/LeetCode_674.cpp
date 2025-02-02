class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int lastNum = nums[0];
        int counter = 1, result = 1;
        for (size_t i = 1; i < nums.size(); i++) {
            if (lastNum < nums[i]) {
                counter++;
                lastNum = nums[i];
                result = max(result, counter);
                continue;
            }
            lastNum = nums[i];
            counter = 1;
        }
        return result;
    }
};
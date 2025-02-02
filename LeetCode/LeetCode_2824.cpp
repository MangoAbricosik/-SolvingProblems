class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int result = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target)
                    result++;
            }
        }
        return result;
    }
};
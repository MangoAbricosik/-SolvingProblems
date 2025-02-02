class Solution {
public:
    inline void reverse(int& val) {
        val = val == 0 ? 1 : 0;
    }

    int minOperations(vector<int>& nums) {
        int counter = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + 2 < nums.size()) {
                    counter++;
                    reverse(nums[i]);
                    reverse(nums[i + 1]);
                    reverse(nums[i + 2]);
                }
                else
                    return -1;
            }
        }
        return counter;
    }
};
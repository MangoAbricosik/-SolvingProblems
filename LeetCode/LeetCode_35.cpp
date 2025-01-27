class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        bool lastPlus = false;
        while (l <= r) {
            m = (l + r) / 2;

            if (nums[m] == target)
                return m;

            if (nums[m] < target) {
                l = m + 1;
                lastPlus = true;
            }
            else {
                r = m - 1;
                lastPlus = false;
            }
        }

        if (lastPlus)
            return ++m;
        else
            return m;
    }
};
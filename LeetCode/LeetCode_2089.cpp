class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lowerThen = 0, good = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] < target)
                lowerThen++;
            else if (nums[i] == target)
                good++;
        }

        vector<int> result;
        for (size_t i = 0; i < good; i++) {
            result.push_back(lowerThen + i);
        }
        return result;
    }
};
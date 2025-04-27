class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int leftDiff = min(minIdx, maxIdx) + 1;
        int rightDiff = nums.size() - max(minIdx, maxIdx);
        int middleDiff = abs(minIdx - maxIdx);

        return min({ leftDiff + middleDiff,leftDiff + rightDiff,middleDiff + rightDiff });
    }
};
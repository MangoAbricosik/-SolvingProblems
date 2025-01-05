class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                result[i] = nums[i];
            }
            else {
                int targetIndex = (i + nums[i]) % n;
                if (targetIndex < 0) {
                    targetIndex += n;
                }

                result[i] = nums[targetIndex];
            }
        }

        return result;
    }
};
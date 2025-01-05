class Solution {
public:
	int minOperations(vector<int>& nums) {
		int result = 0;
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i] <= nums[i - 1]) {
				result += abs(nums[i] - nums[i - 1]) + 1;
				nums[i] += abs(nums[i] - nums[i - 1]) + 1;
			}
		}
		return result;
	}
};
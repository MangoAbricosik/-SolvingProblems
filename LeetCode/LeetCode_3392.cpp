class Solution {
public:
	int countSubarrays(vector<int>& nums) {
		int n = nums.size(), counter = 0;
		for (size_t i = 2; i < n; i++) {
			if (nums[i - 1] == (nums[i - 2] + nums[i]) * 2)
				counter++;
		}
		return counter;
	}
};
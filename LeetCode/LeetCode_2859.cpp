class Solution {
public:
	int sumIndicesWithKSetBits(vector<int>& nums, int k) {
		int result = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			int sum = 0, copy = i;
			while (copy) {
				sum += copy & 1;
				copy >>= 1;
			}
			if (sum == k)
				result += nums[i];
		}
		return result;
	}
};
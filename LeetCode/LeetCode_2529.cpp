class Solution {
public:
	int maximumCount(vector<int>& nums) {
		auto pos = 0, neg = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				pos++;
			if (nums[i] < 0)
				neg++;
		}
		return max(pos, neg);
	}
};
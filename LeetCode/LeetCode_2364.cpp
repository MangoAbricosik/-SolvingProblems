class Solution {
public:
	long getTotal(long n) {
		n--;
		if (n == 1)
			return 1;
		return n + getTotal(n);
	}
	long long countBadPairs(vector<int>& nums) {
		unordered_map<int, int> dict;
		long long counter = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			counter += dict[nums[i] - i];
			dict[nums[i] - i]++;
		}
		return (nums.size() > 1 ? getTotal(nums.size()) : 0) - counter;
	}
};
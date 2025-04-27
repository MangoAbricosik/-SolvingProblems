class Solution {
public:
	int tryUp(vector<int> nums) {
		int last = nums[0], counter = 0;
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i] < last) {
				counter++;
				nums[i] = last;
				i -= 1;
			}
			last = nums[i];
		}
		return counter;
	}

	int tryDown(vector<int> nums) {
		int last = nums[0], counter = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < last) {
				counter++;
				nums[i - 1] = nums[i];
				i - 2 >= 0 ? i -= 2 : i--;
			}
			last = nums[i];
		}
		return counter;
	}

	bool checkPossibility(vector<int>& nums) {
		if (min(tryDown(nums), tryUp(nums)) <= 1)
			return true;
		return false;
	}
};
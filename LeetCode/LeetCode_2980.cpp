class Solution {
public:
	bool hasTrailingZeros(vector<int>& nums) {
		int counter = 0;
		for (auto& item : nums) {
			if (item % 2 == 0)
				counter++;
		}
		if (counter >= 2)
			return true;
		return false;
	}
};
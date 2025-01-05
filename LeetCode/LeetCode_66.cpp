class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1] += 1;

		int to_much = 0;
		reverse(digits.begin(), digits.end());
		for (auto i = 0; i < digits.size(); i++) {
			digits[i] += to_much;
			to_much = 0;
			if (digits[i] > 9) {
				to_much += 1;
				digits[i] = 0;
			}
		}
		if (to_much != 0) {
			digits.push_back(1);
		}
		reverse(digits.begin(), digits.end());
		return digits;
	}
};
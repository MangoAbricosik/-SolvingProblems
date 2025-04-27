class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		queue<int> lower, upper;
		int eqCounter = 0;
		for (auto& item : nums) {
			if (item < pivot) {
				lower.push(item);
				continue;
			}
			if (item > pivot) {
				upper.push(item);
				continue;
			}
			eqCounter++;
		}

		vector<int> result;
		while (!lower.empty()) {
			result.push_back(lower.front());
			lower.pop();
		}
		result.insert(result.end(), eqCounter, pivot);
		while (!upper.empty()) {
			result.push_back(upper.front());
			upper.pop();
		}
		return result;
	}
};
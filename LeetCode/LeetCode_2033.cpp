class Solution {
public:
	int minOperations(vector<vector<int>>& grid, int x) {
		vector<int> arr;
		for (auto line : grid) {
			for (auto val : line)
				arr.push_back(val);
		}

		sort(arr.begin(), arr.end());
		int counter = 0, mid = arr[arr.size() / 2], last = arr[0] % x;
		for (auto val : arr) {
			if (val % x != last)
				return -1;
			counter += abs(mid - val) / x;
		}
		return counter;
	}
};
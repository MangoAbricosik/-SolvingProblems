class Solution {
public:
	int xorOperation(int n, int start) {
		vector<int> arr;
		for (size_t i = 0; i < n; i++) {
			arr.push_back(start + 2 * i);
		}
		int result = arr[0];
		for (size_t i = 1; i < arr.size(); i++) {
			result = result ^ arr[i];
		}
		return result;
	}
};
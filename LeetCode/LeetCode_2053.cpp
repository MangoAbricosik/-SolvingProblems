class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		map<string, int> dict;
		for (auto item : arr)
			dict[item]++;

		int counter = 1;
		for (auto item : arr) {
			if (dict[item] == 1) {
				if (k == counter)
					return item;
				counter++;
			}
		}
		return "";
	}
};
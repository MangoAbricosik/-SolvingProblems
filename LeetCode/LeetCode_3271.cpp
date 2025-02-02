class Solution {
public:
	string stringHash(string s, int k) {
		vector<string> arr;
		for (size_t i = 0; i < s.size(); i += k) {
			arr.push_back(s.substr(i, k));
		}

		string result;
		for (size_t i = 0; i < arr.size(); i++) {
			int temp = 0;
			for (auto item : arr[i])
				temp += item - 'a';
			temp %= 26;
			result.push_back(temp + 'a');
		}

		return result;
	}
};
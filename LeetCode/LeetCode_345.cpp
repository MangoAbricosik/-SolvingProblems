class Solution {
public:
	string reverseVowels(string s) {
		unordered_map<char, int> dict{ {'A', 1}, {'a', 1},{'E', 1}, {'e', 1},{'I', 1}, {'i', 1}, {'O', 1}, {'o', 1},{'U', 1}, {'u', 1} };
		vector<char> arr;
		for (auto& item : s)
			if (dict[item])
				arr.push_back(item);
		reverse(arr.begin(), arr.end());
		for (int i = 0, j = 0; i < s.size(); i++) {
			if (dict[s[i]]) {
				s[i] = arr[j];
				j++;
			}
		}
		return s;
	}
};
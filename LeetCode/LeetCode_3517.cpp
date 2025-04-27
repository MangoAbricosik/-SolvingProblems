class Solution {
public:
	string smallestPalindrome(string s) {
		map<char, int> dict;
		for (auto& item : s)
			dict[item]++;

		string res;
		pair<int, char> temp;
		bool problem = false;
		for (auto& [first, second] : dict) {
			if (second % 2 == 0)
				res.append(second / 2, first);
			else {
				res.append(second / 2, first);
				temp = { second, first };
				problem = true;
			}
		}
		string rev = res;
		reverse(rev.begin(), rev.end());
		if (problem)
			res.append(1, temp.second);
		res.append(rev);
		return res;
	}
};
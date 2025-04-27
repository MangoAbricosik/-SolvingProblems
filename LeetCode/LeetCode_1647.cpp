class Solution {
public:
	int minDeletions(string s) {
		unordered_map<char, int> dict;
		for (auto& item : s)
			dict[item]++;

		unordered_set<int> st;
		int counter = 0;
		for (auto& [first, second] : dict) {
			while (st.find(second) != st.end()) {
				second--;
				counter++;
			}
			if (second != 0)
				st.insert(second);
		}
		return counter;
	}
};
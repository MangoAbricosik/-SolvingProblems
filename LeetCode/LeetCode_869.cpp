class Solution {
	vector<char> doPow(int val, bool fin) {
		string s_val;
		if (fin)
			s_val = to_string(val);
		else
			s_val = to_string((int)pow(2, val));

		vector<char> temp;
		for (size_t i = 0; i < s_val.size(); i++) {
			temp.push_back(s_val[i]);
		}
		sort(temp.begin(), temp.end());
		return temp;
	}
public:
	bool reorderedPowerOf2(int n) {
		set<vector<char>> dict;
		for (size_t i = 0; i < 30; i++) {
			dict.insert(doPow(i, false));
		}

		auto res = doPow(n, true);
		if (dict.find(res) != dict.end())
			return true;
		return false;
	}
};
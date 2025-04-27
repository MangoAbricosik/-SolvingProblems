class Solution {
public:
	bool isHappy(int n) {
		set<int> dict;
		while (dict.find(n) == dict.end()) {
			if (n == 1)
				return true;

			string temp = to_string(n);
			dict.insert(n);
			n = 0;
			for (size_t i = 0; i < temp.size(); i++) {
				n += pow(int(temp[i] - '0'), 2);
			}
		}
		return false;
	}
};
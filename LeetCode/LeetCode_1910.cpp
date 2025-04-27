class Solution {
public:
	string removeOccurrences(string s, string part) {
		for (int i = 0; i < s.size(); i++) {
			auto test = s.substr(i, part.size());
			if (s.substr(i, part.size()) == part) {
				s.erase(i, part.size());
				i -= part.size();
				if (i < 0)
					i = -1;
			}
		}
		return s;
	}
};
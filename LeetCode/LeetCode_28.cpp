class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == haystack)
			return 0;
		if (needle.size() > haystack.size())
			return -1;
		for (size_t i = 0; i < haystack.size(); i++) {
			if (needle == haystack.substr(i, needle.size()))
				return i;
		}
		return -1;
	}
};
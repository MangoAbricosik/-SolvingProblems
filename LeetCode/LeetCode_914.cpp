class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int>m;
		for (int d : deck)
			m[d]++;
		int gcd = m[deck[0]];
		for (auto i : m)
			gcd = std::gcd(gcd, i.second);
		return gcd != 1;
	}
};
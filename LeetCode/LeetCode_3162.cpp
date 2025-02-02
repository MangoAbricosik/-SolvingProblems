class Solution {
public:
	int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int result = 0;
		set<pair<int, int>> dict;
		for (size_t i = 0; i < nums1.size(); i++) {
			for (size_t j = 0; j < nums2.size(); j++) {
				if ((nums1[i] % (nums2[j] * k)) == 0) {
					result++;
				}
			}
		}
		return result;
	}
};
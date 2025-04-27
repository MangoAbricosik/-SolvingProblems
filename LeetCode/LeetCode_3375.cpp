class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		set<int> st;
		for (auto item : nums) {
			if (item < k)
				return -1;
			st.insert(item);
		}
		if (st.find(k) != st.end())
			st.erase(k);
		return st.size();
	}
};
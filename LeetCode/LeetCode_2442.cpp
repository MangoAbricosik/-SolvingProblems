class Solution {
public:
	int countDistinctIntegers(vector<int>& nums) {
		set<int> dict;
		for (auto item : nums) {
			dict.insert(item);
			string temp = to_string(item);
			reverse(temp.begin(), temp.end());
			dict.insert(stoi(temp));
		}
		return dict.size();
	}
};
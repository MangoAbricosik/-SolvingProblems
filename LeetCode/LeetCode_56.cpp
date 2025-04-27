class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end());
		for (auto& item : intervals) {
			if (res.empty() || item[0] > res.back()[1])
				res.push_back(item);
			else
				res.back()[1] = max(res.back()[1], item[1]);
		}
		return res;
	}
};
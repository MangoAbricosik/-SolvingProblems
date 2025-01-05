class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int, vector<int>> mp;
		for (size_t i = 0; i < groupSizes.size(); i++) {
			mp[groupSizes[i]].push_back(i);
		}

		vector<vector<int>> result;
		for (auto item : mp) {
			int i = 0;
			int n = item.second.size();
			int sumIndex = 0;
			while (n - sumIndex > 0) {
				vector<int> temp;
				int last = i;
				for (; i < item.first + last; i++) {
					temp.push_back(item.second[i]);
				}
				sumIndex += item.first;
				result.push_back(temp);
			}
		}

		return result;
	}
};
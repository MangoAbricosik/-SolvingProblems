class Solution {
public:
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
		vector<int> count(pow(grid.size(), 2) + 1, 0);
		for (size_t i = 0; i < grid.size(); i++) {
			for (size_t j = 0; j < grid[i].size(); j++) {
				count[grid[i][j]]++;
			}
		}

		vector<int> result(2);
		for (size_t i = 1; i < pow(grid.size(), 2) + 1; i++) {
			if (count[i] == 2)
				result[0] = i;
			else if (count[i] == 0)
				result[1] = i;
		}
		return result;
	}
};
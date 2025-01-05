class Solution {
public:
	int minimumOperations(vector<vector<int>>& grid) {
		int result = 0, last;
		for (size_t i = 0; i < grid[0].size(); i++) {
			last = grid[0][i];
			for (size_t j = 1; j < grid.size(); j++) {
				if (grid[j][i] <= last) {
					result += (last - grid[j][i]) + 1;
					last = (last - grid[j][i]) + 1 + grid[j][i];
				}
				else
					last = grid[j][i];

			}
		}
		return result;
	}
};
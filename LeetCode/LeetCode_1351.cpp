class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int result = 0;
		for (int j = 0, i = grid.size() - 1; j < grid[0].size() && i >= 0;) {
			if (grid[i][j] < 0) {
				result += grid[i].size() - j;
				i--;
			}
			else {
				j++;
			}
		}
		return result;
	}
};
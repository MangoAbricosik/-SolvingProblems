class Solution {
public:
	int deleteGreatestValue(vector<vector<int>>& grid) {
		int total = 0;
		const int constGridSize = grid[0].size();

		for (auto& item : grid)
			sort(item.begin(), item.end());

		for (size_t y = 0; y < constGridSize; y++) {
			int max = 0;
			for (size_t i = 0; i < grid.size(); i++) {
				max = std::max(grid[i][grid[i].size() - 1], max);
				grid[i].pop_back();
			}
			total += max;
		}
		return total;
	}
};
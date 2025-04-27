class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> result;
		for (size_t i = 0; i < matrix.size(); i++) {
			vector<pair<int, int>> max;
			int fullmax = *std::min_element(matrix[i].begin(), matrix[i].end());

			for (size_t j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == fullmax) {

					int temp = INT_MIN;
					for (size_t z = i; z < matrix.size(); z++) {
						temp = std::max(temp, matrix[z][j]);
					}
					for (int z = i; z >= 0; z--) {
						temp = std::max(temp, matrix[z][j]);
					}
					if (temp == fullmax)
						result.push_back(fullmax);
				}
			}
		}
		return result;
	}
};
#define condition res.size() != matrix.size() * matrix[0].size()
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int iBase = matrix.size() - 1, jBase = matrix[0].size();
		int i = 0, j = 0, counter = 1;
		vector<int> res;
		while (condition) {
			for (int temp = 0; temp < jBase && condition; temp++, j++) {
				res.push_back(matrix[i][j]);
			}
			j--; i++;
			for (int temp = 0; temp < iBase && condition; temp++, i++) {
				res.push_back(matrix[i][j]);
			}
			j--; i--;
			iBase--; jBase--;
			for (int temp = 0; temp < jBase && condition; temp++, j--) {
				res.push_back(matrix[i][j]);
			}

			j++; i--;
			for (int temp = 0; temp < iBase && condition; temp++, i--) {
				res.push_back(matrix[i][j]);
			}
			j++; i++;
			jBase--; iBase--;
		}
		return res;
	}
};
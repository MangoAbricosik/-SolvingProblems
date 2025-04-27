class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, -1));

		int i = 0, j = 0, counter = 1;
		while (counter != pow(n, 2) + 1) {
			while (j < n && matrix[i][j] == -1) {
				matrix[i][j] = counter;
				counter++;
				j++;
			}
			j--;
			i++;
			while (i < n && matrix[i][j] == -1) {
				matrix[i][j] = counter;
				counter++;
				i++;
			}
			j--;
			i--;
			while (j >= 0 && matrix[i][j] == -1) {
				matrix[i][j] = counter;
				counter++;
				j--;
			}
			j++;
			i--;
			while (i >= 0 && matrix[i][j] == -1) {
				matrix[i][j] = counter;
				counter++;
				i--;
			}
			j++;
			i++;
		}
		return matrix;
	}
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix[0].size(); i++) {
            for (size_t j = i + 1; j < matrix[0].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (size_t i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (size_t z = 0; z < 4; z++) {
            for (size_t i = 0; i < mat[0].size(); i++) {
                for (size_t j = i + 1; j < mat[0].size(); j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
            for (size_t i = 0; i < mat.size(); i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
            if (mat == target)
                return true;
        }
        return false;
    }
};
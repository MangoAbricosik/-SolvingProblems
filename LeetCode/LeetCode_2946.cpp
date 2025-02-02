class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        auto copy = mat;
        if (mat.size() < k)
            k = k % mat[0].size();
        for (size_t i = 0; i < mat.size(); i++) {
            if (i % 2 == 0) {
                for (size_t j = 0; j < k; j++) {
                    copy[i].push_back(copy[i][j]);
                }
                copy[i].erase(copy[i].begin(), copy[i].begin() + k);
            }
            else {
                for (size_t j = mat[i].size() - 1, z = 0; z < k; z++) {
                    copy[i].emplace(copy[i].begin(), copy[i][j]);
                }
                copy[i].erase(copy[i].end() - k, copy[i].end());
            }
        }
        if (copy == mat)
            return true;
        return false;
    }
};
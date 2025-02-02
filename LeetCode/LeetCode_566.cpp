class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
            return mat;

        vector<vector<int>> result(r, vector<int>(c));
        vector<int> temp;
        for (auto item : mat)
            for (auto inner_item : item)
                temp.push_back(inner_item);

        auto it = temp.begin();
        for (auto& item : result) {
            for (auto& inner_item : item) {
                inner_item = *it++;
            }
        }

        return result;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (size_t i = 1; i < numRows + 1; i++) {
            vector<int> temp(i);
            *temp.begin() = 1;
            *(temp.end() - 1) = 1;

            if (i > 2) {
                for (size_t j = 1; j < temp.size() - 1; j++) {
                    temp[j] = result[i - 2][j - 1] + result[i - 2][j];
                }
            }

            result.push_back(temp);
        }
        return result;
    }
};
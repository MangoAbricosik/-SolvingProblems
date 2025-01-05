class Solution {
public:
    vector<int>  getRow(int rowIndex) {
        vector<vector<int>> result;
        for (size_t i = 1; i < rowIndex + 2; i++) {
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

        if (rowIndex == 0) {
            vector<int> temp = { 1 };
            return temp;
        }

        return result[rowIndex];
    }
};
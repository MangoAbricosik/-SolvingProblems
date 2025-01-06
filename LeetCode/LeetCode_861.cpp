class Solution {
public:
    void invert(vector<int>& vec) {
        for (size_t i = 0; i < vec.size(); i++) {
            vec[i] = vec[i] == 0 ? 1 : 0;
        }
    }

    int binarySum(vector<int>& vec) {
        int result = 0;
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[vec.size() - 1 - i] == 1) {
                result += pow(2, i);
            }
        }
        return result;
    }

    int gridBinarySum(vector<vector<int>> grid) {
        int result = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            result += binarySum(grid[i]);
        }
        return result;
    }

    int matrixScore(vector<vector<int>>& grid) {
        for (size_t i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                invert(grid[i]);
            }
        }

        pair<int, int> pr;
        for (size_t i = 0; i < grid[0].size(); i++) {
            pr.first = pr.second = 0;
            for (size_t j = 0; j < grid.size(); j++) {
                grid[j][i] == 0 ? pr.first++ : pr.second++;
            }
            if (pr.first > pr.second) {
                for (size_t j = 0; j < grid.size(); j++) {
                    grid[j][i] = grid[j][i] == 0 ? 1 : 0;
                }
            }
        }

        return gridBinarySum(grid);
    }
};
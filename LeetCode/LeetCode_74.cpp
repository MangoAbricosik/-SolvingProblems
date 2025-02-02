class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int last = 0;
        for (size_t i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] > target && target >= matrix[last][0]) {
                last = i - 1;
                break;
            }
            last = i;
        }

        int l = 0, r = matrix[last].size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (matrix[last][m] == target)
                return true;

            if (matrix[last][m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        if (r >= 0 && l >= 0 && matrix[last][min(l, r)] == target)
            return true;

        return false;
    }
};
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto exepted = heights;
        sort(exepted.begin(), exepted.end());

        int result = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            if (exepted[i] != heights[i])
                result++;
        }

        return result;
    }
};
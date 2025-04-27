class Solution {
public:
    long long getMaximumForCurIndx(vector<int> heights, int indx) {
        heights.emplace(heights.begin(), 0);

        auto maxIndx = heights.begin() + indx + 1;

        int last = INT_MAX;
        long long total = 0;

        while (heights.begin() != maxIndx) {
            last = min(*maxIndx, last);
            total += last;
            *maxIndx = last;
            maxIndx--;
        }

        maxIndx = heights.begin() + indx + 1;
        maxIndx++;
        last = INT_MAX;
        while (maxIndx != heights.end() && heights.end() != maxIndx) {
            last = min(*maxIndx, last);
            total += last;
            *maxIndx = last;
            maxIndx++;
        }

        return total;
    }

    long long maximumSumOfHeights(vector<int>& heights) {
        long long maximum = INT_MIN;
        for (size_t i = 0; i < heights.size(); i++) {
            maximum = max(getMaximumForCurIndx(heights, i), maximum);
        }
        return maximum;
    }
};
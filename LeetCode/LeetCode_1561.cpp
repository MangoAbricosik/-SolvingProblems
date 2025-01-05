class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int result = 0;
        sort(piles.begin(), piles.end());
        for (size_t i = 0, j = 0; i < piles.size(); i += 3, j++) {
            result += *(piles.end() - 2 - (i - j));
        }
        return result;
    }
};
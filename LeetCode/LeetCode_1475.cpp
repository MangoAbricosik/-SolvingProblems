class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result;
        for (size_t i = 0; i < prices.size(); i++) {
            int tempSize = result.size();
            for (size_t j = i + 1; j < prices.size(); j++) {
                if (prices[i] >= prices[j]) {
                    result.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if (tempSize == result.size())
                result.push_back(prices[i]);
        }
        return result;
    }
};
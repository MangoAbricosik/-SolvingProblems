class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for (size_t i = 0; i < costs.size() && coins - costs[i] > -1; i++) {
            coins -= costs[i];
            result++;
        }
        return result;
    }
};
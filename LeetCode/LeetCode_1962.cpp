class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> arr(piles.begin(), piles.end());
        for (size_t i = 0; i < k; i++) {
            int temp = arr.top();
            arr.pop();
            arr.push((temp + 1) / 2);
        }

        long long counter = 0;
        while (!arr.empty()) {
            counter += arr.top();
            arr.pop();
        }

        return counter;
    }
};
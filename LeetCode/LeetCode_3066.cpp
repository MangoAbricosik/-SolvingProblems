class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        for (auto item : nums)
            pq.push(item);

        int counter = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            counter++;
            long long temp = pq.top();
            pq.pop();
            long long res = (min(temp, pq.top()) * 2) + max(temp, pq.top());
            pq.pop();
            pq.push(res);
        }
        if (pq.top() < k)
            return -1;
        return counter;
    }
};
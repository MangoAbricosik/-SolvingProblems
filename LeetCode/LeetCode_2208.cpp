class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum;
        priority_queue<double, std::vector<double>> pq;
        for (auto item : nums) {
            pq.push(item);
            sum += item;
        }
        const double SUM = sum;
        int counter = 0;
        while ((SUM / 2) < sum) {
            counter++;
            sum -= pq.top() / 2;
            double temp = pq.top() / 2;
            pq.pop();
            pq.push(temp);
        }
        return counter;
    }
};
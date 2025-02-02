class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> counter;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key)
                counter[nums[i + 1]]++;
        }

        int val = -1, sum = -1;
        for (auto item : counter) {
            if (sum < item.second) {
                sum = item.second;
                val = item.first;
            }
        }
        return val;
    }
};
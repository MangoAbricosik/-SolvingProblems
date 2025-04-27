class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> arr(nums.begin(), nums.end());

        long long counter = 0;
        for (size_t i = 0; i < k; i++) {
            int temp = arr.top();
            counter += temp;


            if (temp == 1) {
                counter += (k - 1 - i);
                break;
            }

            arr.pop();
            arr.push((temp + 2) / 3);
        }
        return counter;
    }
};
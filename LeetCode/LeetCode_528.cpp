class Solution {
    vector<float> arr;
public:
    Solution(vector<int>& w) {
        long long sum = accumulate(w.begin(), w.end(), 0);

        arr.push_back(float(w[0]) / float(sum));
        for (size_t i = 1; i < w.size(); i++) {
            arr.push_back(float(w[i]) / float(sum) + arr[i - 1]);
        }
    }

    int pickIndex() {
        float value = (float)rand() / (float)RAND_MAX;

        for (size_t i = 0; i < arr.size(); i++) {
            if (value <= arr[i])
                return i;
        }

        return rand() % arr.size() - 1;
    }
};
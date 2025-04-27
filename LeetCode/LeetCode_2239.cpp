class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (auto item : nums)
            arr.push_back(make_pair(abs(item), item));

        sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
            });

        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i].first != arr[i - 1].first)
                return arr[i - 1].second;
        }
        return arr[arr.size() - 1].second;
    }
};
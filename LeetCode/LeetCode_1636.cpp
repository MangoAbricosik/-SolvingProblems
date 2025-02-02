class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> counter;
        for (auto item : nums)
            counter[item]++;

        vector<pair<int, int>> arr;
        for (auto item : counter) {
            arr.push_back(make_pair(item.first, item.second));
        }
        sort(arr.begin(), arr.end(), [](pair<int, int> first, pair<int, int> second) {
            if (first.second == second.second) {
                return first.first > second.first;
            }
            return first.second < second.second;
            });

        vector<int> result;
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = 0; j < arr[i].second; j++) {
                result.push_back(arr[i].first);
            }
        }
        return result;
    }
};
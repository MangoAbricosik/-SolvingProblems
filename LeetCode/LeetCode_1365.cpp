class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        auto copy = nums;
        sort(copy.rbegin(), copy.rend());
        copy.push_back(INT_MIN);
        unordered_map<int, int> dict;
        int temp = *copy.begin();
        for (size_t i = 1; i < copy.size(); i++) {
            if (copy[i] != temp)
                dict[copy[i - 1]] = copy.size() - i - 1;
            temp = copy[i];
        }

        vector<int> result;
        for (auto item : nums)
            result.push_back(dict[item]);

        return result;
    }
};
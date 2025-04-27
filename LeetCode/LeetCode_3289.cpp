class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> dict;
        vector<int> res;
        auto it = nums.begin();
        while (res.size() < 2) {
            dict[*it]++;
            if (dict[*it] >= 2)
                res.push_back(*it);
            it++;
        }
        return res;
    }
};
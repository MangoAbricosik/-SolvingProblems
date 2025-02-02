class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for (auto& item : nums)
            if (item % 2 == 0)
                result.push_back(item);
        for (auto& item : nums)
            if (item % 2 != 0)
                result.push_back(item);
        return result;
    }
};
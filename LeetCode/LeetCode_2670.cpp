class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> prefix, suffixe, result;

        set<int> dict;
        for (size_t i = 0; i < nums.size(); i++) {
            dict.insert(nums[i]);
            prefix.push_back(dict.size());
        }
        dict.clear();
        suffixe.push_back(0);
        for (int i = nums.size() - 1; i != -1; i--) {
            dict.insert(nums[i]);
            suffixe.push_back(dict.size());
        }

        for (size_t i = 0; i < nums.size(); i++) {
            result.push_back(prefix[i] - suffixe[suffixe.size() - 2 - i]);
        }
        return result;
    }
};
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> dict;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                int temp = nums[i] * nums[j];
                ans += 8 * dict[temp];
                dict[temp]++;
            }
        }
        return ans;
    }
};
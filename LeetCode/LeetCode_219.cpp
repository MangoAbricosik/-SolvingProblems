class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (size_t i = 0; i < nums.size(); i++) {
            if (!mp.emplace(nums[i], i).second) {
                if (k >= (i - mp[nums[i]]))
                    return true;
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (auto item : nums1)
            mp[item]++;

        set<int> st;
        for (auto item : nums2)
            if (mp[item] > 0)
                st.insert(item);

        vector<int> result;
        for (auto item : st)
            result.push_back(item);

        return result;
    }
};
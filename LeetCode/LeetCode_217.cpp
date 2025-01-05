class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for (auto item : nums) {
            if (!st.insert(item).second)
                return true;
        }
        return false;
    }
};
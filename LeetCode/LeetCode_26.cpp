class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (!st.insert(*it).second) {
                auto temp_it = it;
                it--;
                *temp_it = '_';
            }
        }
        return st.size();
    }
};
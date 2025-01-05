class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix = { 0 };
        for (size_t i = 0; i < gain.size(); i++) {
            prefix.push_back(gain[i] + prefix[i]);
        }
        return *max_element(prefix.begin(), prefix.end());
    }
};
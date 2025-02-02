class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mp;
        for (auto item : arr) {
            if (mp[item * 2] >= 1 || (item % 2 == 0 ? mp[item / 2] >= 1 : 0)) {
                return true;
            }
            mp[item]++;
        }
        return false;
    }
};
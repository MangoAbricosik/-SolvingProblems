class Solution {
    int getSum(int val) {
        if (val == 0)
            return 0;
        return val + getSum(val - 1) % 1000000007;
    }
    int rev(int val) {
        string temp = to_string(val);
        reverse(temp.begin(), temp.end());
        return stoi(temp);
    }
public:
    int countNicePairs(vector<int>& nums) {
        map<int, int> dict;
        for (auto item : nums)
            dict[item - rev(item)]++;

        int count = 0, pairs = -1;
        for (auto item : dict) {
            if (item.second >= 2) {
                count += getSum(item.second - 1);
            }
        }
        return count % 1000000007;
    }
};
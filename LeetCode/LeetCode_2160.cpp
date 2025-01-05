class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        return stoi(to_string(str[0] - 48) + to_string(str[2] - 48)) + stoi(to_string(str[1] - 48) + to_string(str[3] - 48));
    }
};
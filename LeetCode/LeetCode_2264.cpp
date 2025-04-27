class Solution {
public:
    string largestGoodInteger(string num) {
        string temp = "---";
        for (size_t i = 2; i < num.size(); i++) {
            if (num[i - 2] == num[i - 1] && num[i - 2] == num[i])
                temp = max(num.substr(i - 2, 3), temp);
        }
        return temp == "---" ? "" : temp;
    }
};
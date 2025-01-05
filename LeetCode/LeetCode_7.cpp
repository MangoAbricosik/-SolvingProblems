class Solution {
public:
    int reverse(int x) {
        std::string num = std::to_string(x);
        std::reverse(num.begin(), num.end());

        if (num.size() == 1)
            return stoi(num);

        while (num[0] == '0') {
            num.erase(num.begin());
        }

        if (num[num.size() - 1] == '-') {
            num.erase(num.end() - 1);
            num.insert(num.begin(), '-');
        }

        if (stol(num) > INT_MAX || stol(num) < INT_MIN)
            return 0;
        return stoi(num);
    }
};
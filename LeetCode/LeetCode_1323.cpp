class Solution {
public:
    int maximum69Number(int num) {
        string str = to_string(num);
        for (auto& item : str) {
            if (item == '6') {
                item = '9';
                break;
            }
        }
        return stoi(str);
    }
};
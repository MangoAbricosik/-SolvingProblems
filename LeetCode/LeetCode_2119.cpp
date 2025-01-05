class Solution {
public:
    bool isSameAfterReversals(int num) {
        std::string sNum = std::to_string(num);

        if (sNum.size() == 1)
            return true;

        for (size_t i = 0; i < 2; i++) {
            std::reverse(sNum.begin(), sNum.end());

            while (sNum[0] == '0') {
                sNum.erase(sNum.begin());
            }

            if (sNum[sNum.size() - 1] == '-') {
                sNum.erase(sNum.end() - 1);
                sNum.insert(sNum.begin(), '-');
            }
        }

        return stoi(sNum) == num ? true : false;
    }
};
class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = INT_MIN;
        string temp;

        std::istringstream stream(s);
        while (stream >> temp) {
            if (isdigit(temp[0])) {
                if (last < stoi(temp))
                    last = stoi(temp);
                else
                    return false;
            }
        }
        return true;
    }
};
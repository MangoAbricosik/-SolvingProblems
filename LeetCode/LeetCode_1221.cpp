class Solution {
public: 
    int balancedStringSplit(string s) {
        int result = 0;
        pair<int, int> counter;
        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i])
            {
            case 'R':
                counter.first++;
                break;
            case 'L':
                counter.second++;
                break;
            }
            if (counter.first > 0 && counter.first == counter.second) {
                result++;
                counter.first = counter.second = 0;
            }
        }
        return result;
    }
};
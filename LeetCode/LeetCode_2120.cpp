class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> result;
        for (size_t i = 0; i < s.size(); i++) {
            int counter = 0;
            auto pos = startPos;
            bool stop = false;
            for (size_t y = i; y < s.size(); y++) {
                switch (s[y])
                {
                case 'U':
                    if (pos[0] - 1 >= 0) {
                        pos[0]--;
                        counter++;
                    }
                    else
                        stop = true;
                    break;
                case 'R':
                    if (pos[1] + 1 < n) {
                        pos[1]++;
                        counter++;
                    }
                    else
                        stop = true;
                    break;
                case 'D':
                    if (pos[0] + 1 < n) {
                        pos[0]++;
                        counter++;
                    }
                    else
                        stop = true;
                    break;
                case 'L':
                    if (pos[1] - 1 >= 0) {
                        pos[1]--;
                        counter++;
                    }
                    else
                        stop = true;
                    break;
                }
                if (stop)
                    break;
            }
            result.push_back(counter);
        }
        return result;
    }
};
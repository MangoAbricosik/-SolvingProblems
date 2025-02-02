class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> dict;
        for (auto item : tasks)
            dict[item]++;

        int result = 0;
        for (auto item : dict) {
            if (item.second < 2)
                return -1;

            while (item.second != 4 && item.second != 2 && item.second != 0) {
                item.second -= 3;
                result++;
            }

            if (item.second == 4) {
                item.second -= 4;
                result += 2;
            }
            else if (item.second == 2) {
                item.second -= 2;
                result += 1;
            }
        }
        return result;
    }
};
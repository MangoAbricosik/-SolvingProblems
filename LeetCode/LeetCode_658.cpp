class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> counter;
        for (auto item : moves)
            counter[item]++;

        if (counter['U'] - counter['D'] == 0 && counter['L'] - counter['R'] == 0)
            return true;
        return false;
    }
};
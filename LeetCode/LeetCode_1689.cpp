class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (auto item : n) {
            if (item - 48 > max)
                max = item - 48;
        }
        return max;
    }
};
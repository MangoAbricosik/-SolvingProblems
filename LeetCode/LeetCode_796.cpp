class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i != s.size(); i++) {
            auto test = goal.substr(i, s.size());
            if (s == goal.substr(i, s.size()))
                return true;
            else
                goal.push_back(goal[goal.size() - s.size()]);
        }
        return false;
    }
};
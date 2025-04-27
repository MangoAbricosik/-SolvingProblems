class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int distinct = 0;
        vector<int> ans;
        unordered_map<int, int> ball, color;
        for (auto& item : queries) {
            int pos = item[0], c = item[1];
            if (ball.count(pos))
                if (--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if (++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};
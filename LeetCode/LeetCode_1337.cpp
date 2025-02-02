class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> counter;
        for (int i = 0; i < mat.size(); i++) {
            int temp = count(mat[i].begin(), mat[i].end(), 1);
            counter.insert(make_pair(temp, i));
        }

        vector<int> result;
        for (auto item : counter) {
            if (k == 0)
                break;
            result.push_back(item.second);
            --k;
        }
        return result;
    }
};
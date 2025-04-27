class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> firstDict, secondDict;
        for (auto item : grid)
            firstDict[item]++;

        int n = grid.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < n; j++) {
                auto temp = std::move(grid[i][j]);
                grid[i][j] = std::move(grid[j][i]);
                grid[j][i] = std::move(temp);
            }
        }

        for (auto item : grid)
            secondDict[item]++;

        vector<vector<int>> temp;
        for (auto& item : firstDict) {
            if (secondDict[item.first] > 0 && item.second > 0) {
                if (secondDict[item.first] == 1)
                    item.second += secondDict[item.first] - 1;
                else if (secondDict[item.first] > 1)
                    item.second *= secondDict[item.first];
            }
            else {
                temp.push_back(item.first);
            }
        }

        for (auto item : temp) {
            firstDict.erase(item);
        }

        int counter = 0;
        for (auto item : firstDict)
            counter += item.second;
        return counter;
    }
};
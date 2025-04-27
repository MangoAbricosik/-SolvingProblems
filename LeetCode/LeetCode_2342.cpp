class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> dict;
        for (size_t i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);

            int sum = 0;
            while (!temp.empty()) {
                sum += *(temp.end() - 1) - '0';
                temp.erase(temp.end() - 1);
            }

            dict[sum].push_back(nums[i]);
        }

        for (auto& item : dict) {
            sort(item.second.begin(), item.second.end());
        }

        int max = -1;
        for (auto& item : dict) {
            if (item.second.size() >= 2) {
                max = std::max(item.second[item.second.size() - 1] + item.second[item.second.size() - 2], max);
            }
        }

        return max;
    }
};
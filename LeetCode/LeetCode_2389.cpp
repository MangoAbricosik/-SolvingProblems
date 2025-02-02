class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); i++) {
            nums[i] == nums[i] + nums[i - 1];
        }

        vector<int> result;
        for (size_t i = 0; i < queries.size(); i++) {
            int temp = 0, check = result.size();
            for (size_t j = 0; j < nums.size(); j++) {
                temp += nums[j];
                if (temp == queries[i]) {
                    result.push_back(j + 1);
                    break;
                }
                else if (temp > queries[i]) {
                    result.push_back(j);
                    break;
                }
            }
            if (check == result.size())
                result.push_back(nums.size());
        }
        return result;
    }
};
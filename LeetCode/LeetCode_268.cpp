class Solution {
public:
    int sup(unsigned int n) {
        if (n == 0)
            return 0;
        return n + (sup(n - 1));
    }

    int missingNumber(vector<int>& nums) {
        int full = sup(nums.size());
        return full - std::accumulate(nums.begin(), nums.end(), 0);
    }
};
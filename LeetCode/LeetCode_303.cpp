class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(0);
        for (size_t i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
private:
    vector<int> prefix;
};
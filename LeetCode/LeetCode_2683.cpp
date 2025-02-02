class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for (auto item : derived)
            sum += item;

        if (sum % 2 == 0)
            return true;
        else
            return false;
    }
};
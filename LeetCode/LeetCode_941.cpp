class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        if (arr.size() < 3)
            return false;

        size_t i = 1;
        bool goUp = false, goDown = false;
        for (; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                if (i == 1)
                    return false;
                goUp = true;
                break;
            }
        }

        for (; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) {
                return false;
            }
            else
                goDown = true;
        }

        if (goUp && goDown)
            return true;
        return false;
    }
};
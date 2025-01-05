class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxAr = 0;
        while (l < r) {
            if (min(height[r], height[l]) * (r - l) > maxAr)
                maxAr = min(height[r], height[l]) * (r - l);

            if (r > l && height[l] > height[r])
                r--;
            else
                l++;
        }
        return maxAr;
    }
};
class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return 0;
        if (x == 1)
            return 1;

        bool lastPlus;
        long l = 1, r = x, m = -1;
        while (l <= r) {
            m = l + (r - l) / 2;

            if ((m * m) == x)
                return m;

            if ((m * m) < x) {
                l = m + 1;
                lastPlus = true;
            }
            else {
                r = m - 1;
                lastPlus = false;
            }
        }

        return static_cast<int>(std::round(r));  // Округляем результат до ближайшего целого

        return l;
    }
};
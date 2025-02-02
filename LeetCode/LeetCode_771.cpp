class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> st;
        for (auto item : jewels)
            st.insert(item);

        int result = 0;
        for (auto item : stones) {
            if (st.find(item) != st.end())
                result++;
        }
        return result;
    }
};
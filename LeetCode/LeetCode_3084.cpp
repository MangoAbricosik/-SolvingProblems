class Solution {
public:
    long long factorial(long long n) {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    long long countSubstrings(string s, char c) {
        unordered_map<char, long long> dict;
        for (auto item : s)
            dict[item]++;

        return dict[c] * (dict[c] + 1) / 2;
    }
};
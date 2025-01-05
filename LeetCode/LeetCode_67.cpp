class Solution {
public:
    string addBinary(string a, string b) {
        auto a_it = a.end() - 1;
        auto b_it = b.end() - 1;

        int to_much = 0;
        std::string ans;

        while (true) {
            ans.push_back(((int(*a_it) + int(*b_it) + to_much) % 2) + '0');
            to_much = ((int(*a_it) - 48) + (int(*b_it) - 48) + to_much) / 2;

            if (b_it == b.begin() && a_it == a.begin() && to_much == 0)
                break;

            if (b_it != b.begin())
                b_it--;
            else
                *b_it = '0';
            if (a_it != a.begin())
                a_it--;
            else
                *a_it = '0';

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
    int a, b;
public:
    void CreateNormaly(string& str) {
        while (a != 0 || b != 0) {
            str.push_back(a > b ? 'a' : 'b');
            a > b ? a-- : b--;
        }
    }

    void CreateWhileBad(string& str) {
        while (abs(a - b) > 1 && a > 0 && b > 0) {
            str.push_back(a > b ? 'a' : 'b');
            str.push_back(a > b ? 'a' : 'b');
            str.push_back(a > b ? 'b' : 'a');

            if (a > b) {
                a -= 2;
                b--;
            }
            else {
                b -= 2;
                a--;
            }
        }
    }

    string strWithout3a3b(int a, int b) {
        this->a = a;
        this->b = b;
        string result;
        if (abs(a - b) > 1)
            CreateWhileBad(result);
        CreateNormaly(result);
        return result;
    }
};
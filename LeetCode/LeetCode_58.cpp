class Solution {
public:
    int lengthOfLastWord(string s) {
        std::istringstream stream(s);
        std::string temp_f, temp_s;

        stream >> temp_f;
        while (stream >> temp_s)
            if (temp_s != "")
                temp_f = temp_s;
        return temp_f.size();
    }
};
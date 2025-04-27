 class Solution {
     bool checkWord(string& word, set<char>& st) {
         for (auto ch : word) {
             if (st.find(ch) == st.end())
                 return false;
         }
         return true;
     }
 public:
     int countConsistentStrings(string allowed, vector<string>& words) {
         set<char> st;
         for (auto item : allowed)
             st.insert(item);

         int result = 0;
         for (auto& word : words) {
             if (checkWord(word, st))
                 result++;
         }
         return result;
     }
 };
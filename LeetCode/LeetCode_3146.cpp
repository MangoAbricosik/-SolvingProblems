 class Solution {
 public:
     int findPermutationDifference(string s, string t) {
         unordered_map<char, int> original;
         for (size_t i = 0; i < s.size(); i++)
             original[s[i]] = i;
         int result = 0;    
         for (int i = 0; i < t.size(); i++) {
             result += abs(original.find(t[i])->second - i);
         }
         return result;
     }
 };
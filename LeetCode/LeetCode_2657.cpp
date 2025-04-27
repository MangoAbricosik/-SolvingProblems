class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> dictA, dictB;
        int counter = 0;
        vector<int> result;
        for (size_t i = 0; i < A.size(); i++) {
            if (dictA[A[i]] == 0)
                dictA[A[i]] = 1;
            if (dictB[B[i]] == 0)
                dictB[B[i]] = 1;

            if (dictA[B[i]] == 1 && dictB[A[i]] == 1) {
                counter += (A[i] == B[i] ? 1 : 2);
            }
            else if (dictA[B[i]] == 1 || dictB[A[i]] == 1) {
                counter += 1;
            }

            result.push_back(counter);
        }
        return result;
    }
};
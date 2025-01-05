class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int gMax = 0, pMax = 0, mMax = 0;
        int gTotal = 0, pTotal = 0, mTotal = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (size_t j = 0; j < garbage[i].size(); j++) {
                switch (garbage[i][j])
                {
                case 'G':
                    gMax = max(gMax, i);
                    gTotal++;
                    break;
                case 'P':
                    pMax = max(pMax, i);
                    pTotal++;
                    break;
                case 'M':
                    mMax = max(mMax, i);
                    mTotal++;
                    break;
                }
            }
        }

        int result = 0;
        result += gTotal + accumulate(travel.begin(), travel.begin() + gMax, 0);
        result += pTotal + accumulate(travel.begin(), travel.begin() + pMax, 0);
        result += mTotal + accumulate(travel.begin(), travel.begin() + mMax, 0);

        return result;
    }
};

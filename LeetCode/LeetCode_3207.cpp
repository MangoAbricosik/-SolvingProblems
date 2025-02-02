class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (enemyEnergies[0] > currentEnergy)
            return 0;

        long long result = currentEnergy;
        for (size_t i = 1; i < enemyEnergies.size(); i++) {
            result += enemyEnergies[i];
        }

        return result / enemyEnergies[0];
    }
};
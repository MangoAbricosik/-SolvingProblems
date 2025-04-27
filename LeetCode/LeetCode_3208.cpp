class Solution {
	inline void addToResults(int& counter, int& k, vector<int>& results) {
		if (counter >= k - 1) {
			results.push_back(counter + 1);
		}
		counter = 0;
	}
public:
	int numberOfAlternatingGroups(vector<int>& colors, int k) {
		int n = colors.size();
		for (size_t i = 0; i < n; i++) {
			colors.push_back(colors[i]);
		}

		vector<int> results;
		int counter = 0;
		for (size_t i = 0; i < n + k - 2; i++) {
			if (colors[i] != colors[i + 1])
				counter++;
			else {
				addToResults(counter, k, results);
			}
		}
		addToResults(counter, k, results);

		counter = 0;
		for (auto item : results)
			if (item >= k - 1)
				counter += item - k + 1;

		return counter;
	}
};
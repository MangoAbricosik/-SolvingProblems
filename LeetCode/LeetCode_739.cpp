class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<pair<int, int>> st;
		vector<pair<int, int>> arr;
		for (int i = 0; i < temperatures.size(); i++) {
			if (st.empty() || st.top().first >= temperatures[i])
				st.push({ temperatures[i], i });
			else {
				while (!st.empty() && st.top().first < temperatures[i]) {
					arr.push_back({ st.top().second, i - st.top().second });
					st.pop();
				}
				st.push({ temperatures[i], i });
			}
		}
		while (!st.empty()) {
			arr.push_back({ st.top().second, 0 });
			st.pop();
		}
		sort(arr.begin(), arr.end());
		vector<int> result;
		for (auto& [first, second] : arr)
			result.push_back(second);
		return result;;
	}
};
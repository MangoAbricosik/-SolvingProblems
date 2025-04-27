class Solution {
public:
	vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		priority_queue<pair<int, string>> pq;
		for (size_t i = 0; i < names.size(); i++) {
			pq.push(make_pair(heights[i], names[i]));
		}

		vector<string> result;
		while (!pq.empty()) {
			result.push_back(pq.top().second);
			pq.pop();
		}
		return result;
	}
};
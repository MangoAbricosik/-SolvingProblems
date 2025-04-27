class Solution {
public:
	long long pickGifts(vector<int>& gifts, int k) {
		priority_queue<int> pq;
		for (size_t i = 0; i < gifts.size(); i++) {
			pq.push(gifts[i]);
		}

		for (size_t i = 0; i < k; i++) {
			pq.push(sqrt(pq.top()));
			pq.pop();
		}

		long long ans = 0;
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
		return ans;
	}
};
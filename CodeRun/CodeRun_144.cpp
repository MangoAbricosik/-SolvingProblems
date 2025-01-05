#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#pragma warning( disable : 4996) // for test

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int n, i = 0;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (auto& item : arr) {
		cin >> item.first;
		item.second = i;
		i++;
	}

	map<int, int> mp;
	stack<pair<int, int>> st;
	for (size_t i = 0; i < arr.size(); i++) {
		while (!st.empty() && arr[i].first < st.top().first) {
			mp.emplace(st.top().second, arr[i].second);
			st.pop();
		}
		st.push(arr[i]);
	}
	while (!st.empty()) {
		mp.emplace(st.top().second, -1);
		st.pop();
	}
	for (auto item : mp)
		cout << item.second << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996) // for test

vector<int> getPath(vector<int>& from, int finish) {
	vector<int> path;
	for (size_t v = finish; v != -1; v = from[v]) {
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	return path;
}

vector<vector<int>> convert(vector<vector<int>> a)
{
	vector<vector<int>> adjList(a.size());
	for (int i = 0; i < a.size(); i++)
	{

		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] != 0)
			{
				adjList[i].push_back(j);
			}
		}
	}
	return adjList;
}

const int INF = 1e9;

vector<int> bfs(vector<vector<int>>& graph, int start, vector<int>& from) {
	vector<int> dist(graph.size(), INF);
	queue<int> q;

	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : graph[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				from[to] = v;
				q.push(to);
			}
		}
	}

	return dist;
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int sizeOfTable, start, finish;
	cin >> sizeOfTable;

	vector<vector<int>> arr(sizeOfTable, vector<int>(sizeOfTable));
	for (size_t i = 0; i < sizeOfTable; i++) {
		for (size_t j = 0; j < sizeOfTable; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> start >> finish;
	start--;
	finish--;

	arr = convert(arr);
	vector<int> from(arr.size(), -1);
	vector<int> dist = bfs(arr, start, from);
	from = getPath(from, finish);
	if (dist[finish] == INF) {
		cout << "-1\n";
	}
	else if (dist[finish] == 0) {
		cout << dist[finish] << "\n";
	}
	else {
		cout << dist[finish] << "\n";
		for (auto item : from) {
			cout << ++item << " ";
		}
		cout << endl;
	}

	return 0;
}
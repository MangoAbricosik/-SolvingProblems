#include <iostream>
#include <queue>

using namespace std;

#pragma warning( disable : 4996) // for test

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

vector<int> bfs(vector<vector<int>>& graph, int start) {
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
	vector<int> dist = bfs(arr, start);

	if (dist[finish] == INF) {
		cout << "-1\n";
	}
	else {
		cout << dist[finish] << "\n";
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996) // for test

void dfs(vector<vector<char>> &a, int &y, int &x, vector<vector<int>> &visited, int &counter) {
	visited[y][x] = 1;
	counter++;

	static vector<int> dy = { -1,0,1,0 };
	static vector<int> dx = { 0,1,0,-1 };

	for (size_t d = 0; d < dy.size(); d++){
		int ty = y + dy[d];
		int tx = x + dx[d];

		if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx]  == '.' && !visited[ty][tx])
			dfs(a, ty, tx, visited, counter);
	}
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int size;
	cin >> size;

	vector<vector<char>> arr(size, vector<char>(size));
	vector<vector<int>> visited(size, vector<int>(size));

	for (size_t i = 0; i < size; i++){
		for (size_t j = 0; j < size; j++){
			cin >> arr[i][j];
		}
	}

	int x, y;
	cin >> y >> x;
	x--;
	y--;

	int counter = 0;

	dfs(arr, y, x, visited, counter);

	cout << counter << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#pragma warning( disable : 4996) // for test

void doPrefixSum(const vector<vector<int>>& matrix, vector<vector<long long>>& prefixMatrix) {
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < matrix[i].size(); j++) {
			if (j != 0)
				prefixMatrix[i][j] = matrix[i][j] + prefixMatrix[i][j - 1];
			else
				prefixMatrix[i][j] = matrix[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int xMatrix, yMartix, countsOfCall;
	cin >> xMatrix >> yMartix >> countsOfCall;
	vector<vector<int>> matrix(xMatrix, vector<int>(yMartix));
	vector<vector<long long>> prefixMatrix(xMatrix, vector<long long>(yMartix));

	for (auto& item : matrix)
		for (auto& inner_item : item)
			cin >> inner_item;

	doPrefixSum(matrix, prefixMatrix);

	for (size_t i = 0; i < countsOfCall; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --x2; --y1; --y2;

		long long sum = 0;
		for (size_t i = x1; i < x2 + 1; ++i) {
			sum += (prefixMatrix[i][y2] - prefixMatrix[i][y1]) + matrix[i][y1];
		}
		cout << sum << endl;
	}


	return 0;
}
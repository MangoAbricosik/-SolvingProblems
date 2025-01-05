#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#pragma warning( disable : 4996) // for test

void fillMatrix(vector<vector<int>>& matrix, int& s, int& c) {
	matrix.resize(s, vector<int>(c));
	for (size_t i = 0; i < s; i++) {
		for (size_t j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin); // for test

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> first, second, temp(k, vector<int>(n)), result(n, vector<int>(k));
	fillMatrix(first, n, m);
	fillMatrix(second, m, k);



	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < k; j++) {
			result[i][j] = 0;
			for (size_t z = 0; z < m; z++) {
				result[i][j] += first[i][z] * second[z][j];
			}
		}
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < k; j++) {
			temp[j][i] = result[i][j];
		}
	}
	result = temp;

	for (auto item : result) {
		for (auto inner_item : item) {
			cout << inner_item << " ";
		}
		cout << '\n';
	}
	return 0;
}
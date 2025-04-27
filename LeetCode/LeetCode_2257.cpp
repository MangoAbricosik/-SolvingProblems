class Solution {
public:
	int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		vector<vector<int>> field(m, vector<int>(n));
		for (auto& item : guards) {
			field[item[0]][item[1]] = 1;
		}
		for (auto& item : walls) {
			field[item[0]][item[1]] = 2;
		}

		for (auto& item : guards) {
			field[item[0]][item[1]] = 1;

			// rigth
			for (int j = item[1] + 1; j < n && field[item[0]][j] != 2 && field[item[0]][j] != 1; j++) {
				field[item[0]][j] = 3;
			}

			// left
			for (int j = item[1] - 1; j >= 0 && field[item[0]][j] != 2 && field[item[0]][j] != 1; j--) {
				field[item[0]][j] = 3;
			}

			// down
			for (int j = item[0] + 1; j < m && field[j][item[1]] != 2 && field[j][item[1]] != 1; j++) {
				field[j][item[1]] = 3;
			}

			// up
			for (int j = item[0] - 1; j >= 0 && field[j][item[1]] != 2 && field[j][item[1]] != 1; j--) {
				field[j][item[1]] = 3;
			}
		}

		int counter = 0;
		for (auto str : field) {
			for (auto val : str)
				if (val == 0)
					counter++;
		}
		return counter;;

	}
};
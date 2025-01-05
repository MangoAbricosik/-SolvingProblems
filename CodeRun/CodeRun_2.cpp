#include <iostream>
#include <string>
#include <algorithm> 

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;
    int n = rows, m = cols;
    int map[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for (int cln = m - 2; cln >= 0; --cln) {
        map[n - 1][cln] += map[n - 1][cln + 1];
    }
    for (int row = n - 2; row >= 0; --row) {
        map[row][m - 1] += map[row + 1][m - 1];
    }
    for (int row = n - 2; row >= 0; --row) {
        for (int cln = m - 2; cln >= 0; --cln) {
            map[row][cln] += std::min(map[row + 1][cln], map[row][cln + 1]);
        }
    }
    int result = map[0][0];
    std::cout << result << std::endl;

    return 0;
}
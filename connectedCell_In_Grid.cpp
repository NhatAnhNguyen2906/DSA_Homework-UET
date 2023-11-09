#include <iostream>
#include <vector>
using namespace std;

// Check if a given cell is within the bounds of the matrix
bool isValidCell(int i, int j, int n, int m) {
    return (i >= 0 && j >= 0 && i < n && j < m);
}

// Recursive function to calculate the size of the region
int findRegionSize(vector<vector<int>>& matrix, int i, int j, int n, int m) {
    int size = 1;
    // Mark the current cell as visited
    matrix[i][j] = 0;
    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Recursively visit all adjacent cells
    for (int k = 0; k < 8; ++k) {
        if (isValidCell(i + row[k], j + col[k], n, m) && matrix[i + row[k]][j + col[k]] == 1) {
            size += findRegionSize(matrix, i + row[k], j + col[k], n, m);
        }
    }
    return size;
}

int connectedCell(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxRegionSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                int regionSize = findRegionSize(matrix, i, j, n, m);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << connectedCell(matrix) << endl;
    return 0;
}

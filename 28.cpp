#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n, m, target;

    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements (sorted row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter target value to search: ";
    cin >> target;

    bool found = sol.searchMatrix(matrix, target);

    if (found)
        cout << "\n Target found in matrix!\n";
    else
        cout << "\n Target not found in matrix.\n";

    return 0;
}

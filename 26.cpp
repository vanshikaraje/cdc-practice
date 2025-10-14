#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = 0;      
        int rowIndex = 0;      
        
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) count++;
            }
            if (count > maxCount) {
                maxCount = count;
                rowIndex = i;
            }
        }
        return {rowIndex, maxCount};
    }
};

int main() {
    Solution sol;
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter elements (0 or 1 only):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> result = sol.rowAndMaximumOnes(mat);
    cout << "\nRow with maximum ones: " << result[0] << endl;
    cout << "Number of ones in that row: " << result[1] << endl;

    return 0;
}

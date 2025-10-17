#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if we can place 'k' cows
    // with at least 'minDist' distance apart
    bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
        int cowsPlaced = 1; // place first cow at the first stall
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                cowsPlaced++;
                lastPos = stalls[i];
                if (cowsPlaced == k) return true; // all cows placed
            }
        }
        return false;
    }

    // Main function to find maximum minimum distance
    int solve(int n, int k, vector<int>& stalls) {
        sort(stalls.begin(), stalls.end()); // sort stall positions

        int low = 1; // minimum possible distance
        int high = stalls[n - 1] - stalls[0]; // maximum possible distance
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                ans = mid;      // valid distance, try for bigger
                low = mid + 1;
            } else {
                high = mid - 1; // invalid, try smaller distance
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;

    // Example test cases
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "Maximum minimum distance: " << sol.solve(stalls1.size(), k1, stalls1) << endl;

    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << "Maximum minimum distance: " << sol.solve(stalls2.size(), k2, stalls2) << endl;

    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << "Maximum minimum distance: " << sol.solve(stalls3.size(), k3, stalls3) << endl;

    return 0;
}

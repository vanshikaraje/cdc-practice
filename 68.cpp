#include <bits/stdc++.h>
using namespace std;

// Mock API (for testing locally)
int bad = 4;
bool isBadVersion(int version) {
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "First bad version: " << sol.firstBadVersion(n) << endl;
    return 0;
}

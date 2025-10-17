#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if Koko can finish all bananas at speed k in h hours
    bool canEatAll(vector<int>& piles, int k, int h) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;  // same as ceil(pile / k)
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, mid, h)) {
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

    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}

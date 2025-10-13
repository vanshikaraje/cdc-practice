#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = nums[0]; // 🎒 bag (sum till now)
    int maxSum = nums[0];     // ⭐ best bag so far

    for (int i = 1; i < nums.size(); i++) {
        // decision: continue bag OR start new bag
        currentSum = max(nums[i], currentSum + nums[i]);

        // update best
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n;   
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << maxSubArray(nums) << endl;

    return 0;
}

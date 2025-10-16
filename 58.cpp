#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; // track the minimum price so far
        int maxProfit = 0;        // track the maximum profit so far

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}

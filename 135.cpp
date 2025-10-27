class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array with a large number
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0; // Base case

        // Compute dp[i] for all i up to amount
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If not possible, return -1
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

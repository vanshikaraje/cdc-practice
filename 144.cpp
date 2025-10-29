class Solution {
public:
    int coinChangeFrom(int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = coinChangeFrom(amount - coin, coins);
            if (res >= 0 && res < minCoins) {
                minCoins = 1 + res;
            }
        }

        return (minCoins == INT_MAX) ? -1 : minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        return coinChangeFrom(amount, coins);
    }
};

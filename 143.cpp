class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) sum += n;
        
        // if target is not possible or (sum + target) is odd → no solutions
        if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
        
        int newTarget = (sum + target) / 2;
        
        // dp[i] = number of ways to make sum i
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;  // one way to make sum 0
        
        for (int num : nums) {
            for (int j = newTarget; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[newTarget];
    }
};

class Solution {
private:
    int robFrom(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) return 0;           // base case
        if (dp[i] != -1) return dp[i];           // return cached result

        int rob = nums[i] + robFrom(i + 2, nums, dp);
        int skip = robFrom(i + 1, nums, dp);

        return dp[i] = max(rob, skip);
    }

    int robLinear(vector<int>& nums, int start, int end) {
        vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
        vector<int> dp(sub.size(), -1);
        return robFrom(0, sub, dp);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // only one house

        int case1 = robLinear(nums, 0, n - 2);  // exclude last house
        int case2 = robLinear(nums, 1, n - 1);  // exclude first house

        return max(case1, case2);
    }
};

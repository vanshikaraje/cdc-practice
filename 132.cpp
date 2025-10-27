class Solution {
public:
    int robFrom(int i, vector<int>& nums, vector<int>& dp) {
       if(i>=nums.size())return 0;
       if(dp[i]!=-1)return dp[i];
       int rob = nums[i]+robFrom(i+2,nums,dp);
       int skip = robFrom(i+1,nums,dp);
       return dp[i] = max(rob,skip);
    }
    int rob(vector<int>& nums){
        vector<int>dp(nums.size(), -1);
        return robFrom(0,nums,dp);
    }
};

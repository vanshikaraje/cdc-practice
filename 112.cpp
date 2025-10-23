class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        // Add every alternate element starting from index 0
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

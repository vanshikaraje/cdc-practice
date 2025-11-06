class Solution {
public:
    // Function to find the first occurrence of target
    int findFirst(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else low  = mid+1;
        }
        return ans;
    }

    // Function to find the last occurrence of target
    int findLast(vector<int>& nums, int target) {
        int low = 0; int high = nums.size()-1;
        int ans  = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid -1;
            }
            else low = mid+1;
        }
     return ans;
    }

    // Main function to return the start and end indices
    vector<int> searchRange(vector<int>& nums, int target) {
      int lb = findFirst(nums,target);
      if(lb == nums.size()  || nums[lb] != target) return {-1,-1};
      return {lb,findLast(nums,target)-1};
    }
};

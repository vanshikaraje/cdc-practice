class Solution {
public:
    // Helper function to check if mid can be used to split into <= k parts
    bool isPossible(vector<int>& nums, int k, int mid) {
        int subarrays = 1;
        int sum = 0;

        for (int num : nums) {
            if (sum + num > mid) {
                subarrays++;
                sum = num;
                if (subarrays > k) return false;
            } else {
                sum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); // Minimum possible answer
        int high = accumulate(nums.begin(), nums.end(), 0); // Maximum possible answer
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

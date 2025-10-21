#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        k = nums.size() - k; // convert kth largest to index
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k) return nums[pivotIndex];
            else if (pivotIndex < k) left = pivotIndex + 1;
            else right = pivotIndex - 1;
        }
        return -1; // should not reach here
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // stores next greater of each num in nums2
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];

            // Pop smaller or equal elements (they can't be next greater)
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // If stack empty -> no next greater
            if (st.empty()) nextGreater[curr] = -1;
            else nextGreater[curr] = st.top();

            // Push current element
            st.push(curr);
        }

        // Prepare answer for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};

// Driver code for VS Code (omit this part in LeetCode)
int main() {
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

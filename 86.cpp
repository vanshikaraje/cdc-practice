#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : ans) cout << num << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int n = nums.size();
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;  
}

int main() {
    int n;
    cin >> n;  // take number of elements

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // take elements
    }

    int newLength = removeDuplicates(nums);

    cout << newLength << endl;  // print new length
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

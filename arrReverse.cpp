#include<bits/stdc++.h>
using namespace std;
void rotateArray(vector<int>&nums){
    int k = k%n;
    int n = nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main() {
    int n, k;
    cin >> n >> k;  // take size and k

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // take elements
    }

    rotateArray(nums, k);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
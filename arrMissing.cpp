#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>&nums){
    int missing = nums.size();
    for(int i = 0;i<nums.size();i++){
        missing  = missing^i^nums[i];
    }
    return missing;
}
int main(){
    int n ;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"enter"<<n<<"numbers"<<n<<"one is missing :";
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int ans = missingNumber(nums);
    cout<<"the  missing number is :"<<ans<<endl;
return 0;}
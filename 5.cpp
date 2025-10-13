#include<bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>&nums,int k){
    int n = nums.size();
    k = k % n;
     reverse(nums.begin(),nums.end());
     reverse(nums.begin(),nums.begin()+k);
     reverse(nums.begin()+k,nums.end());
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
for(int i = 0;i<n;i++){
    cin>>nums[i];
}
rotateArray(nums,k);

for(int i = 0;i<n;i++){
    cout<<nums[i]<<" ";
}
cout<< endl;
return 0 ;
}

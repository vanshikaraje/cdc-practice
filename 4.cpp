#include<bits/stdc++.h>
using namespace std;
 int removeDuplicates(vector<int>&nums){
    int n = nums.size();
    if(n==0)return 0;

    int i = 0;
    for(int j = 1 ; j<n;j++){
        if(nums[j] != nums[i]){
            nums[i+1]=nums[j];
            i++;
        
        }
    }
        return i +1;
    
 }
 int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
// input an array
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    // remove elements
    int newLenght = removeDuplicates(nums);
    cout<<newLenght << endl;

// loo for removd elemenst
    for(int i =0;i<newLenght;i++){
        cout<<nums[i]<<" ";
    }
    cout<< endl;
    return 0 ;
 }
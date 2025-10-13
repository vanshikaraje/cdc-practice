// #include<bits/stdc++.h>
// using namespace std;
// bool CheckSorted(vector<int>&nums){
//     int countBreak = 0;
//     int n = nums.size();
//     for(int i = 0;i<n;i++){
//         if(nums[i]>nums[(i+1)%n]){
//             countBreak++;
//         }
//         if(countBreak>1){
//             return false;
//         }
//     }
//     return true;  
// }
// int main(){
//     int n;
//     cout<<"enter the element : "<<endl;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i = 0;i<n;i++){
//         cin>>nums[i];
//     }
//     if(CheckSorted(nums))
//     cout<<"true"<<endl;
//     else
//     cout<<"false"<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int CheckSorted(vector<int>&nums){
    int countBreak = 0;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]){
            countBreak++;
        }
        if(countBreak>1){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout<<"enter the elements in array"<<endl;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    if(CheckSorted(nums))
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int longestString(vector<int>nums){
    if(nums.empty())return 0;
    unordered_set<int>s(nums.begin(),nums.end());
    int longest = 0;
   for(int num : s){
        if(!s.count(num-1)){
            int current =  num;
            int streak = 1;
            while(s.count(current+1)){
                current++;
                streak++;
            }
            longest = max(longest,streak);
        }
      }
      return longest;
}
int main(){
    int n;
    cout<<"enter the elements of the array :"<<endl;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int ans =  longestString(nums);
    cout<<ans<<endl;
    return 0;
}

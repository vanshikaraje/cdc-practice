// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
        
//     }
// };
class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int noOfB = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)    {
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB +=(cnt/k);
        return noOfB >=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      long long val = m*1ll*k*1ll;
      if(val>bloomDay.size())return -1;
      int mini = INT_MAX ,maxi = INT_MIN;
      for(int i = 0;i<bloomDay.size();i++){
        mini = min(mini,bloomDay[i]);
        maxi = max(maxi,bloomDay[i]);
      }
      int low = mini,high = maxi;
      while(low<=high){
        int mid = (low+high)/2;
        if(canMakeBouquets(bloomDay,mid,m,k)){
            high = mid-1;
        }
        else low =mid+1;
      }
      return low;
    }
};

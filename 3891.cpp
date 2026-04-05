//op question bhai  Minimum Increase to Maximize Special Indices
#include <bits/stdc++.h>
using namespace std;
long long dp[100001][2];
long long helper(vector<int>& nums,int i,int pos){
    if(i>=nums.size()-1) return 0;
    if(dp[i][pos]!=-1) return dp[i][pos];

    long long  cost=max(0,max(nums[i-1],nums[i+1])+1-nums[i]);

    if(pos) cost+=helper(nums,i+2,pos);
    else{
        long long pick=cost+helper(nums,i+2,0);
        long long skip=cost+helper(nums,i+3,1);
        cost=min(pick,skip);
    }

return dp[i][pos]=cost;
}
int main(){
   memset(dp,-1,sizeof(dp));
   vector<int> nums={17,22,35,33,27,10};
   int n=nums.size();
     if (n % 2) {
       long long ans = 0;
       for (int i = 1; i < n - 1; i += 2) {
           ans += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
       }
       return ans;                    
   }

   long long a= min(helper(nums,1,0),helper(nums,2,1));
   cout<<a;
}
#include<bits/stdc++.h>
using namespace std;
int dp[20000];


int helper(vector<int>&nums,vector<int>&clr,int i,int n){
 if(i==nums.size()) return 0;
 
if(dp[i]!=-1) return dp[i];

int pick=0,notpick=0;

   notpick=helper(nums,clr,i+1,n);
   if(i+1<n && clr[i]==clr[i+1]) pick=nums[i]+helper(nums,clr,i+2,n);
   else  pick=nums[i]+helper(nums,clr,i+1,n);


   return dp[i]=max(pick,notpick);


}
 

int main(){
  memset(dp,-1,sizeof(dp));

vector<int>v={10,1,3,9};
int n=v.size();
vector<int>clr={1,1,1,2};
int ans=helper(v,clr,0,n);
cout<<ans;

}
class Solution {
public:
     int dp[1001][1001];
     int help(int idx,int t,int &n,vector<int>& nums){

         if(t==0) return 0;
        if(idx>=n) return INT_MIN;
        if(dp[idx][t]!=-1) return dp[idx][t];

        int pk=INT_MIN,npk=0;
        npk=help(idx+1,t,n,nums);
      if(t-nums[idx]>=0)  {
        pk=help(idx+1,t-nums[idx],n,nums);
          if(pk!=INT_MIN) pk+=1;
      }
       


        return dp[idx][t]=max(pk,npk);

        

     }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        int n=nums.size();
       memset(dp,-1,sizeof(dp));
       int a= help(0,target,n,nums);
       cout<<a;
       return a==INT_MIN?-1:a;
    }
};
class Solution {
public:
    long  long dp[100001][2];
    long long help(int idx,int prv,string &s,vector<int>& nums)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx][prv]!=-1) return dp[idx][prv];

        long long ans=0;

       if(s[idx]=='0') ans=help(idx+1,0,s,nums);
       else{
          long long take=nums[idx]+help(idx+1,1,s,nums);
           long long prvtake=0;
        if(prv!=1) prvtake= nums[idx-1]+help(idx+1,0,s,nums);

        ans=max(ans,max(take,prvtake));
       }
       return dp[idx][prv]=ans;
    }
    long long maxTotal(vector<int>& nums, string s) {

        memset(dp,-1,sizeof(dp));
         int n=s.size();

        if(n==1) return s[0]=='0'?0:nums[0];


         if (s[0] == '1')
            return nums[0] + help(1, 1, s, nums);
        else
            return help(1, 0, s, nums);
        
    }
};
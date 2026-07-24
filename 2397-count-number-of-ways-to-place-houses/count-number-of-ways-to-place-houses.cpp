class Solution {
public:

    int dp[10001];
    const int MOD=1e9+7;
    int help(int idx,int &n)
    {
         if(idx>=n) return 1;
         if(dp[idx]!=-1)  return dp[idx];
         int ans=0;

         ans=(ans+help(idx+1,n))%MOD;
         ans=(ans+help(idx+2,n))%MOD;

         return dp[idx]=ans;
        
    }
    int countHousePlacements(int n) {

        memset(dp,-1,sizeof(dp));

        long  long a= help(0,n);

        return (a*a*1LL)%MOD;
        
    }
};
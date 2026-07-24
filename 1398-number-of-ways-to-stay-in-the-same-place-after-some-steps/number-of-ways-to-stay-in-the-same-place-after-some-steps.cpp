class Solution {
public:
    int dp[501][501];
    
    const int MOD=1e9+7;

    int help(int idx,int s,int &l)
    {


        if(s==0) return idx==0;
        if(dp[idx][s]!=-1) return dp[idx][s];

        int ans=0;

        if(idx>0) ans=(ans+help(idx-1,s-1,l))%MOD;
        ans=(ans+help(idx,s-1,l))%MOD;
        if(idx+1<l) ans=(ans+help(idx+1,s-1,l))%MOD;

      return dp[idx][s]=ans;
    }
    int numWays(int steps, int arrLen) {

        memset(dp,-1,sizeof(dp));

        return help(0,steps,arrLen);
        
    }
};
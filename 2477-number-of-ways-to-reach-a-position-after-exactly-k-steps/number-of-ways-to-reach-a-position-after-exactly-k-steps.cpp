class Solution {
public:
    int dp[4004][1001];
    const int MOD=1e9+7;
    int help(int idx,int &dest,int k)
    {
        if(idx<0 && idx+k<dest ) return 0;
        if(k==0) return idx==dest;
        int shift=idx+1000;
        if(dp[shift][k]!=-1) return dp[shift][k];

        int ans=0;

        ans=(ans+help(idx+1,dest,k-1))%MOD;
        ans=(ans+help(idx-1,dest,k-1))%MOD;

        return dp[shift][k]=ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));

        return help(startPos,endPos,k);

    }
};
class Solution {
public:
    int dp[101][101][101];
    const int MOD=1e9+7;
    int help(int idx,int n,int p,vector<int>& group, vector<int>& profit)
    {
        
        if(idx==group.size()){
            return n>=0 && p==0;
        }
       // if(n==0) return 0;
        if(dp[idx][n][p]!=-1) return dp[idx][n][p];

        int ans=0;
        ans=(ans+help(idx+1,n,p,group,profit))%MOD;

        if(group[idx] <= n){
        ans = (ans + help(idx+1,
                      n-group[idx],
                      max(0,p-profit[idx]),
                      group,profit)) % MOD;
}


   return dp[idx][n][p]=ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return help(0,n,minProfit,group,profit);
    }
};
class Solution {
public:
     int dp[10001][7][7];
     const  int mod=1e9+7;
     int help(int n,int prv,int sprv,int idx)
     {
      
      if(idx==n) return 1;

      if(dp[idx][prv][sprv]!=-1) return dp[idx][prv][sprv];

      int ans=0;

        for(int k=1;k<=6;k++){
          
          if(prv==0 || (__gcd(prv,k)==1 && prv!=k && sprv!=k)){
             ans=(ans+help(n,k,prv,idx+1))%mod;
          }

        }
        
    return    dp[idx][prv][sprv]=ans;
     }
    int distinctSequences(int n) {

        memset(dp,-1,sizeof(dp));

        return help(n,0,0,0);
        
    }
};
class Solution {
public:
     int dp[1<<9]; 

     int help(vector<int>& strength, int k,int x,int &n,int mask){

        if(mask==(1<<n)-1) return 0;

        if(dp[mask]!=-1) return dp[mask];


       int ans=INT_MAX;

       int cnt = 1 + __builtin_popcount(mask)*k;

      for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                
             
                int cost = (strength[i] + cnt - 1) / cnt;

                ans = min(ans,
                          cost + help(strength,k,x,n,mask | (1 << i)));
            }
        }

        return dp[mask] = ans;



     }

    int findMinimumTime(vector<int>& strength, int k) {

        memset(dp,-1,sizeof(dp));
        int n=strength.size();
         
         return help(strength,k,1,n,0);
        
    }
};
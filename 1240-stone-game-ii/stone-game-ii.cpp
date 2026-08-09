class Solution {
public:
      vector<int>suff;
      int dp[101][230];
      int sz;
      int help(int idx,int M){

          if(idx>=sz) return 0;
          if(2*M>=sz-idx) return suff[idx];
          if(dp[idx][M]!=-1) return dp[idx][M];

          int ans=0;
            
            for(int i=1;i<=2*M;i++){
                int opp=help(idx+i,max(M,i));
                ans=max(ans,suff[idx]-opp);
            }

            return dp[idx][M]=ans;

      }
    int stoneGameII(vector<int>& piles) {
        
        int n=piles.size();
        sz=n;
        suff.resize(n,0);
        suff[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=piles[i]+suff[i+1];
        }

        memset(dp,-1,sizeof(dp));

        return help(0,1);
      
    }
};
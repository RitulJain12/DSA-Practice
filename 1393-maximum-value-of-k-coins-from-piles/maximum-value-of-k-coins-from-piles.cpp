class Solution {
public:
    int dp[1001][2001];
    int help(int idx,int k,vector<vector<int>>& piles)
    { 

        if(k==0) return 0;
        if(idx==piles.size()) return -1e9;
        if(dp[idx][k]!=-1) return dp[idx][k];

         int ans=0;

         ans=help(idx+1,k,piles);
         int sum=0;
      for(int i=0;i<piles[idx].size();i++){
         sum += piles[idx][i];

      if(k >= i+1){
        ans = max(ans, sum + help(idx+1, k-(i+1), piles));
    }
}
     return dp[idx][k]=ans;

    }  
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        memset(dp,-1,sizeof(dp));

        return help(0,k,piles);
        
    }
};
class Solution {
public:
    int dp[1001][1001];
    const int mod=1e9+7;
    int help(int i,int j,vector<vector<int>>& grid,int &n,int &m){

      //  if(i<0||i>=n||j<0||j>=m )  return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        if(i+1<n && grid[i+1][j]>grid[i][j]) ans=(ans+1+help(i+1,j,grid,n,m))%mod;
        if(i-1>=0 && grid[i-1][j]>grid[i][j]) ans=(ans+1+help(i-1,j,grid,n,m))%mod;
        if(j-1>=0  &&  grid[i][j-1]>grid[i][j]) ans=(ans+1+help(i,j-1,grid,n,m))%mod;
         if(j+1<m && grid[i][j+1]>grid[i][j]) ans=(ans+1+help(i,j+1,grid,n,m))%mod;
     
      
      return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        memset(dp,-1,sizeof(dp));
        int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         ans=(ans +  help(i,j,grid,n,m))%mod;
        }
       }

       return ans+n*m;
    }
};
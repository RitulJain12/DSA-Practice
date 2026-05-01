class Solution {
    public:
         int dp[201][201];
         int n,m;
         int helper(int i,int j,vector<vector<int>>& d){
    
            if(i==n-1 && j==m-1)  return max(1,1-d[i][j]);
            if(i>=n || j>=m)  return INT_MAX;
            if(dp[i][j]!=-1) return dp[i][j];
    
            int left=helper(i+1,j,d);
            int down=helper(i,j+1,d);
            int need= min(left,down);
              
            return dp[i][j]=max(1,need-d[i][j]);
    
         }
        int calculateMinimumHP(vector<vector<int>>& dungeon) {
            n=dungeon.size();
            m=dungeon[0].size();
            memset(dp,-1,sizeof(dp));
    
            return helper(0,0,dungeon);
        }
    };
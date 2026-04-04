

class Solution {
    public:
    
        int dp[51][51][51];
        int solve(vector<vector<int>>& grid,int r1,int c1,int r2){
              int c2=r1+c1-r2;
              int n=grid.size();
            if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
                grid[r1][c1] == -1 || grid[r2][c2] == -1)
                return -1e9;
    
            if (r1 == n-1 && c1 == n-1)
                return grid[r1][c1];
    
            if (dp[r1][c1][r2] != -1)
                return dp[r1][c1][r2];
    
            int cherries = 0;
    
            if (r1 == r2 && c1 == c2)
                cherries = grid[r1][c1];
            else
                cherries = grid[r1][c1] + grid[r2][c2];
    
            int ans = max({
                solve(grid, r1+1, c1, r2+1),
                solve(grid, r1+1, c1, r2),
                solve(grid, r1, c1+1, r2+1),
                solve(grid, r1, c1+1, r2)
            });
    
            cherries += ans;
    
            return dp[r1][c1][r2] = cherries;
    
        }
        int cherryPickup(vector<vector<int>>& grid) {
            memset(dp,-1,sizeof(dp));
            int a= solve(grid,0,0,0);
            if(a<0)  return 0;
            return a;
        }
    };
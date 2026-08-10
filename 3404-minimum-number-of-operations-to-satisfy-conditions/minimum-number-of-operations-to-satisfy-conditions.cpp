class Solution {
public:
     int dp[1001][11];
     int help(int c,int &n,int &m,int prv,vector<vector<int>>&freq,vector<vector<int>>& grid)
     {
          
             if(c>=m) return 0;
             if(dp[c][prv+1]!=-1) return dp[c][prv+1];

             int cost=INT_MAX;

             for(int i=0;i<=9;i++){
                if(prv==i) continue;
                int nextres=help(c+1,n,m,i,freq,grid);

                if(nextres!=INT_MAX) cost=min(cost,n-freq[c][i]+nextres);

             }


             return dp[c][prv+1]=cost;


     }
    int minimumOperations(vector<vector<int>>& grid) {

        int n=grid.size();

        int m=grid[0].size();

        vector<vector<int>>freq(m,vector<int>(10,0));

        for(int j=0;j<m;j++){

            for(int i=0;i<n;i++){
                freq[j][grid[i][j]]++;
            }
        }


        memset(dp,-1,sizeof(dp));

        return help(0,n,m,-1,freq,grid);
        
    }
};
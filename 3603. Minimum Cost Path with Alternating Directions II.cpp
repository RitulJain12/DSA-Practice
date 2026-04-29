class Solution {
    public:
        
        long long help(int m,int n, vector<vector<int>>& waitCost,vector<vector<long long>> &dp,int i,int j){
    
            if(i>=m || j>=n) return LLONG_MAX;
            if(i==m-1 && j==n-1) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
    
            long long right= help(m,n,waitCost,dp,i+1,j);
            if(right!=LLONG_MAX) right+=(i+2)*1LL*(j+1);
            long long down= help(m,n,waitCost,dp,i,j+1);
            if(down!=LLONG_MAX) down+=(i+1)*1LL*(j+2);
    
            if(i==0 && j==0) return dp[i][j]=min(right,down);
    
            return dp[i][j]=waitCost[i][j]+min(right,down);
    
        }
        long long minCost(int m, int n, vector<vector<int>>& waitCost) {
    
            vector<vector<long long>> dp(m, vector<long long>(n,-1));
            return 1+help(m,n,waitCost,dp,0,0);
    
        }
    };
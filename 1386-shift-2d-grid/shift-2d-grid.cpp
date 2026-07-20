class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int st) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans(n*m,0);
        
        st %= (n * m);
        if (st == 0)
            return grid;
          int k=st;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(k<n*m) ans[k++]=grid[i][j];
               else {ans[0]=grid[i][j];k=1;}
            }
          }
          k=0;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=ans[k++];
            }
          }

          return grid;
    }
};
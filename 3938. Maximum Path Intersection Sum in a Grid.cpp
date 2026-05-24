// 3938. Maximum Path Intersection Sum in a Grid

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int sum=INT_MIN;

        for(int i=0;i<n;i++){

          int curr=grid[i][0];

          for(int j=1;j<m;j++){
          //len 2
             sum=max(sum,curr+grid[i][j]);
         
          if(i>0 && j>0 && i<n-1 && j<m-1 )  sum=max(sum,grid[i][j]);

             curr=max(grid[i][j]+curr,grid[i][j]);

          }

        }


        for(int j=0;j<m;j++){

           int curr=grid[0][j];

           for(int i=1;i<n;i++){
              
              sum=max(sum,curr+grid[i][j]);

                if(i>0 && j>0 && i<n-1 && j<m-1 )  sum=max(sum,grid[i][j]);

                curr=max(curr+grid[i][j],grid[i][j]);

           }

        }


        return sum;
    }
};
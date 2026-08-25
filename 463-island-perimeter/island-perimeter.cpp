class Solution {
public:

 int count(vector<vector<int>>& grid, int i, int j) {
        int sides = 4;
        int n = grid.size();
        int m = grid[0].size();

        if (i > 0 && grid[i-1][j] == 1)
            sides--;

        if (i < n-1 && grid[i+1][j] == 1)
            sides--;

        if (j > 0 && grid[i][j-1] == 1)
            sides--;

        if (j < m-1 && grid[i][j+1] == 1)
            sides--;

        return sides;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
      
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    perimeter += count(grid, i, j);
                }
            }
        }

        return perimeter;
    
    }
};
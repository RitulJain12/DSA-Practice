/*
 the center of magic sequence should always be 5 
*/
class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {

        vector<int> freq(10, 0);

        
        for (int r = i; r < i + 3; r++) {
            for (int c = j; c < j + 3; c++) {
                int x = grid[r][c];

                if (x < 1 || x > 9 || freq[x])
                    return false;

                freq[x] = 1;
            }
        }

        int target = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

    
        for (int r = i; r < i + 3; r++) {
            int sum = 0;
            for (int c = j; c < j + 3; c++)
                sum += grid[r][c];

            if (sum != target)
                return false;
        }

    
        for (int c = j; c < j + 3; c++) {
            int sum = 0;
            for (int r = i; r < i + 3; r++)
                sum += grid[r][c];

            if (sum != target)
                return false;
        }

    
        int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

        return diag1 == target && diag2 == target;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        if (rows < 3 || cols < 3)
            return 0;

        int ans = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {

                
                if (grid[i + 1][j + 1] != 5)
                    continue;

                if (isMagic(grid, i, j))
                    ans++;
            }
        }

        return ans;
    }
};
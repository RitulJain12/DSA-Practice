class Solution {
public:
 vector<int> dr = {-1, 0, 1, 0}; 
vector<int> dc = {0, 1, 0, -1}; 
long long dfs(int i, int j, set<pair<int,int>>& vis, vector<vector<int>>& grid) {

    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;

    if(grid[i][j] == 0) return 0;

    if(vis.count({i,j})) return 0;

    vis.insert({i,j});

    long long sum = grid[i][j];

    for(int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        sum += dfs(nr, nc, vis, grid);
    }

    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        set<pair<int,int>>vis;
        int ans=0;

 for(int i = 0; i < n; i++) {
    for(int j = 0; j < grid[0].size(); j++) {

        if(grid[i][j] != 0 && !vis.count({i,j})) {

            long long sum = dfs(i,j,vis,grid);

            if(sum % k == 0)
                ans++;
        }
    }
}
        return ans;
    }
};
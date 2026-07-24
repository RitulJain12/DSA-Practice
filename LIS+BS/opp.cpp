class Solution {
public:
    vector<vector<int>> dp;
    int Helper(vector<vector<int>>& triangle, int i, int j) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j];
        if (dp[i][j] != INT_MIN) return dp[i][j];

        int ans = triangle[i][j] + min(Helper(triangle, i+1, j),
                                       Helper(triangle, i+1, j+1));
        dp[i][j] = ans;
        return ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        dp.assign(n, vector<int>(n, INT_MIN));
        return Helper(triangle, 0, 0);
    }
};


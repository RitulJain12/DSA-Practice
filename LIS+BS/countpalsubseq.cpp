//for all index seprated treat 
long long solve(int i, int j, string &s, vector<vector<long long>> &dp) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j]) {
        return dp[i][j] =
            solve(i + 1, j, s, dp) +
            solve(i, j - 1, s, dp) +
            1;
    }

    return dp[i][j] =
        solve(i + 1, j, s, dp) +
        solve(i, j - 1, s, dp) -
        solve(i + 1, j - 1, s, dp);
}
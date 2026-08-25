class Solution {
public:
    int dp[501][501];

    int help(int i, int j, vector<int>& st, vector<int>& pre) {
        if (i == j)  return 0;

        if (dp[i][j] != -1)   return dp[i][j];

        int ans = 0;

        for (int k = i; k < j; k++) {

            int part1 = pre[k] - (i > 0 ? pre[i - 1] : 0);
            int part2 = pre[j] - pre[k];

            if (part1 < part2) {
                ans = max(ans,
                          part1 + help(i, k, st, pre));
            }
            else if (part2 < part1) {
                ans = max(ans,
                          part2 + help(k + 1, j, st, pre));
            }
            else {
                ans = max(ans,
                          max(
                              part1 + help(i, k, st, pre),
                              part2 + help(k + 1, j, st, pre)
                          ));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> pre(n);

        pre[0] = stoneValue[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + stoneValue[i];

        memset(dp, -1, sizeof(dp));

        return help(0, n - 1, stoneValue, pre);
    }
};
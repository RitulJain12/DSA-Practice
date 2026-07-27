class Solution {
public:
    int n;
    vector<vector<int>> lcp;
    vector<int> dp;

    int solve(int i, string &s) {
        if (i == n) return 0;

        if (dp[i] != -1)  return dp[i];

        int ans = 1; 

        for (int len = 1; i + 2 * len <= n; len++) {

            
            if (lcp[i][i + len] >= len) {
                ans = max(ans, 1 + solve(i + len, s));
            }
        }

        return dp[i] = ans;
    }

    int deleteString(string s) {
        n = s.size();

 
        lcp.assign(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j])
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }

        dp.assign(n, -1);

        return solve(0, s);
    }
};
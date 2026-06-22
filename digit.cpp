class Solution {
public:
    long long dp[16][2][11][2];
    int K;

    long long help(int idx, int tight, int prv, int st, string &x) {

        if (idx == x.size()) return st;

        if (dp[idx][tight][prv][st] != -1)
            return dp[idx][tight][prv][st];

        int limit = tight ? x[idx] - '0' : 9;

        long long ans = 0;

        for (int d = 0; d <= limit; d++) {

            int newTight = tight && (d == limit);


            if (!st && d == 0) {
                ans += help(idx + 1, 0, prv, 0, x);
            }
            else {
            
                if (!st) {
                    ans += help(idx + 1, newTight, d, 1, x);
                }
                
                else if (abs(prv - d) <= K) {
                    ans += help(idx + 1, newTight, d, 1, x);
                }
            }
        }

        return dp[idx][tight][prv][st] = ans;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return help(0, 1, 0, 0, s);
    }

    long long goodIntegers(long long l, long long r, int k) {
        K = k;
        return solve(r) - solve(l - 1);
    }
};
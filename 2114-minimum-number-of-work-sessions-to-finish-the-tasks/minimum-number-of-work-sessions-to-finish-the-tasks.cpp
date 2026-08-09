class Solution {
public:
    int dp[1 << 14][16];
    int ss;
    int help(int mask, int s, vector<int>& tasks, int& n) {

        if (mask == (1 << n) - 1)
            return 0;

        if (dp[mask][s] != -1)
            return dp[mask][s];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            if ((mask & (1 << i)) == 0) {

                
                if (s >= tasks[i]) {

                    ans = min(ans,
                        help(mask | (1 << i),
                             s - tasks[i],
                             tasks, n));
                }

                
                else {

                    ans = min(ans,
                        1 + help(mask | (1 << i),
                                 ss- tasks[i],
                                 tasks, n));
                }
            }
        }

        return dp[mask][s] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {

        int n = tasks.size();

        ss=sessionTime;

        memset(dp, -1, sizeof(dp));

        return 1 + help(0, sessionTime, tasks, n);
    }
};
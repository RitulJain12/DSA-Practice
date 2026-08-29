class Solution {
public:
    int dp[500001][4];

    int help(int idx, int lane, vector<int>& obstacles) {
        int n = obstacles.size();

        if (idx == n - 1)
            return 0;

        if (dp[idx][lane] != -1)
            return dp[idx][lane];

        
        if (obstacles[idx + 1] != lane) {
            return dp[idx][lane] =
                help(idx + 1, lane, obstacles);
        }

       
        int ans = INT_MAX;

        for (int newLane = 1; newLane <= 3; newLane++) {

            if (newLane != lane &&
                obstacles[idx] != newLane) {

                ans = min(ans,
                          1 + help(idx, newLane, obstacles));
            }
        }

        return dp[idx][lane] = ans;
    }

    int minSideJumps(vector<int>& obstacles) {

        memset(dp, -1, sizeof(dp));

        return help(0, 2, obstacles);
    }
};
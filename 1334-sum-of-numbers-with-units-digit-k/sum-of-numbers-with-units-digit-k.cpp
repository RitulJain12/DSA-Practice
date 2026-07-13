class Solution {
public:
    int dp[3001][301];

    int minSize(int num, vector<int>& choice, int idx) {

        if (num == 0) return 0;
        if (idx == choice.size()) return INT_MAX;

        if (dp[num][idx] != -1)
            return dp[num][idx];

        int best = minSize(num, choice, idx + 1);

        if (num >= choice[idx]) {
            int take = minSize(num - choice[idx], choice, idx);

            if (take != INT_MAX)
                best = min(best, 1 + take);
        }

        return dp[num][idx] = best;
    }

    int minimumNumbers(int num, int k) {

        if (num == 0) return 0;

        vector<int> choice;

        int a = k;
        if (a == 0) a = 10;

        while (a <= num) {
            choice.push_back(a);
            a += 10;
        }

        memset(dp, -1, sizeof(dp));

        int ans = minSize(num, choice, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};
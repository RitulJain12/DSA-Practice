
//ques number of powerful integers in a given range 2999


class Solution {
public:
    long long dp[20][2];

    long long solve(string &str, int idx, int &l, int &diff, string &s, int tight) {
        if (idx == str.size()) return 1;

        if (dp[idx][tight] != -1) return dp[idx][tight];

        int limit = (tight ? str[idx] - '0': l);
        long long ans = 0;

        if (idx >= diff) {
            int reqd = s[idx - diff] - '0';
            if (reqd > limit) return 0;

            ans += solve(str, idx + 1, l, diff, s, (tight & (reqd == limit)));
        } 
        else {
            for (int i = 0; i <= limit; i++) {
                int newt = (tight & (i == limit));
             if(i<=l) ans += solve(str, idx + 1, l, diff, s, newt);
            }
        }

        return dp[idx][tight] = ans;
    }

    long long count(long long x, int limit, string s) {
        string str = to_string(x);
        int n = str.size();
        int m = s.size();
        int diff = n - m;

        if (diff < 0) return 0;

        memset(dp, -1, sizeof(dp));
        return solve(str, 0, limit, diff, s, 1);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        for (char c : s) {
            if (c - '0' > limit) return 0;
        }

        long long ans1 = count(finish, limit, s);
        long long ans2 =0;
        if(start>=stoll(s)) ans2=count(start - 1, limit, s);

        return ans1 - ans2;
    }
};
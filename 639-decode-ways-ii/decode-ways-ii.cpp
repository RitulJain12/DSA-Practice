class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> dp;

    long long help(string &s, int i) {
        if (i == s.size()) return 1;
        if (dp[i] != -1) return dp[i];

        long long ans = 0;

        
        if (s[i] == '*') {
            ans = (9LL * help(s, i + 1)) % MOD;
        }
        else if (s[i] != '0') {
            ans = help(s, i + 1);
        }

       
        if (i + 1 < s.size()) {

           
            if (s[i] != '*' && s[i + 1] != '*') {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num >= 10 && num <= 26)
                    ans = (ans + help(s, i + 2)) % MOD;
            }

           
            else if (s[i] == '*' && s[i + 1] != '*') {

                if (s[i + 1] >= '0' && s[i + 1] <= '6') {
                    ans = (ans + 2LL * help(s, i + 2)) % MOD;
                } else {
                    ans = (ans + help(s, i + 2)) % MOD;
                }
            }


            else if (s[i] != '*' && s[i + 1] == '*') {

                if (s[i] == '1') {
                    ans = (ans + 9LL * help(s, i + 2)) % MOD;
                }
                else if (s[i] == '2') {
                    ans = (ans + 6LL * help(s, i + 2)) % MOD;
                }
            }

            else {
                ans = (ans + 15LL * help(s, i + 2)) % MOD;
            }
        }

        return dp[i] = ans % MOD;
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);
        return help(s, 0);
    }
};
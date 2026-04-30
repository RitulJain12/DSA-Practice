class Solution {
    public:
        int dp[11][2][1024][2][2];
    
        int solve(int idx, int tight, int mask, int flag, int lead, string &s) {
    
            if(idx == s.size()) return flag;
    
            if(dp[idx][tight][mask][flag][lead] != -1)
                return dp[idx][tight][mask][flag][lead];
    
            int lmt = tight ? s[idx]-'0' : 9;
            int ans = 0;
    
            for(int i = 0; i <= lmt; i++) {
    
                int newTight = tight & (i == s[idx]-'0');
    
                if(lead && i == 0) {
                    ans += solve(idx+1, newTight, mask, flag, 1, s);
                }
                else {
                    bool newFlag = flag || (mask & (1<<i));
                    ans += solve(idx+1, newTight, mask | (1<<i), newFlag, 0, s);
                }
            }
    
            return dp[idx][tight][mask][flag][lead] = ans;
        }
    
        int numDupDigitsAtMostN(int n) {
            string s = to_string(n);
            memset(dp, -1, sizeof(dp));
    
            return solve(0, 1, 0, 0, 1, s);
        }
    };
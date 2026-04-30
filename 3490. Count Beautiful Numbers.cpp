class Solution {
    public:
        int dp[11][2][82][82];
    
        int solve(string &s, int idx, int tight, int sum, int modp, int targetSum) {
            
            if (sum > targetSum) return 0;
    
            if (idx == s.size()) {
                return (sum == targetSum && modp == 0);
            }
    
            if (dp[idx][tight][sum][modp] != -1) 
                return dp[idx][tight][sum][modp];
    
            int lmt = (tight ? s[idx] - '0' : 9);
            int ans = 0;
    
            for (int i = 0; i <= lmt; i++) {
    
                int newSum = sum + i;
    
                int newMod;
    
                if (i == 0 && sum == 0) {
                    // leading zero case → ignore in product
                    newMod = 1;
                } else {
                    newMod = (modp * i) % targetSum;
                }
    
                int newTight = (tight && (i == s[idx] - '0'));
    
                ans += solve(s, idx + 1, newTight, newSum, newMod, targetSum);
            }
    
            return dp[idx][tight][sum][modp] = ans;
        }
    
        int countUpto(int x) {
            string s = to_string(x);
            int ans = 0;
    
            for (int targetSum = 1; targetSum <= 81; targetSum++) {
    
                memset(dp, -1, sizeof(dp));
    
                ans += solve(s, 0, 1, 0, 1, targetSum);
            }
    
            return ans;
        }
    
        int beautifulNumbers(int l, int r) {
            return countUpto(r) - countUpto(l - 1);
        }
    };
class Solution {
    public:
        int d(string s) {
            unordered_map<int, int> mp;
            int one = 0, zero = 0, freqone = 0, freqzero = 0, ans = 0;
            int n = s.size();
    
            mp[0] = -1;
    
            for (char ch : s) {
                if (ch == '1') freqone++;
                else freqzero++;
            }
    
            for (int i = 0; i < n; i++) {
                char ch = s[i];
                if (ch == '1') one++;
                else zero++;
    
                int diff = one - zero;
    
                if (mp.count(diff + 2)) {
                    int len = i - mp[diff + 2];
                    if (freqone >= len / 2 && freqzero >= len / 2)
                        ans = max(ans, len);
                }
    
                if (mp.count(diff - 2)) {
                    int len = i - mp[diff - 2];
                    if (freqone >= len / 2 && freqzero >= len / 2)
                        ans = max(ans, len);
                }
    
                if (mp.count(diff)) {
                    int len = i - mp[diff];
                    ans = max(ans, len);
                }
    
                if (!mp.count(diff)) {
                    mp[diff] = i;
                }
            }
    
            return ans;
        }
    
        int longestBalanced(string s) {
            int ans = 0;
            ans = max(ans, d(s));
    
            reverse(s.begin(), s.end());
            ans = max(ans, d(s));
    
            return ans;
        }
    };
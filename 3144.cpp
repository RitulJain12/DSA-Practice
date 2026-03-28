class Solution {
    public:
        int dp[1001];
    
        int helper(string &s, int i){
            if(i == s.size()) return 0;
    
            if(dp[i] != -1) return dp[i];
    
            int ans = INT_MAX;
    
            int freq[26] = {0};  
            int unique = 0;
    
            for(int cut = i; cut < s.size(); cut++){
    
            
                if(freq[s[cut] - 'a'] == 0) unique++;
                freq[s[cut] - 'a']++;
    
                int len = cut - i + 1;
    
    
                if(len % unique == 0){
                    int expected = len / unique;
    
                    bool ok = true;
                    for(int k = 0; k < 26; k++){
                        if(freq[k] != 0 && freq[k] != expected){
                            ok = false;
                            break;
                        }
                    }
    
                    if(ok){
                        ans = min(ans, 1 + helper(s, cut + 1));
                    }
                }
            }
    
            return dp[i] = ans;
        }
    
        int minimumSubstringsInPartition(string s) {
            memset(dp, -1, sizeof(dp));
            return helper(s, 0);
        }
    };
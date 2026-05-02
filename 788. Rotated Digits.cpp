//2 method se kaara isko ek to brute force se n*4 me cause 10^4 take n*4 digit or 2nd way digit dp se kar sakte hai

class Solution {
public:
    int dp[10][2][2][2]; 
    

    int solve(string &s, int idx, int tight, int changed, int started) {
        
        
        if(idx == s.size()) {
            return (started && changed);
        }

        if(dp[idx][tight][changed][started] != -1)
            return dp[idx][tight][changed][started];

        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for(int i = 0; i <= limit; i++) {

            int newStarted = started || (i != 0);
            int newTight = tight & (i == s[idx] - '0');

        
            if(!newStarted) {
                ans += solve(s, idx + 1, newTight, changed, 0);
            }
            else {
                
                if(i == 3 || i == 4 || i == 7) continue;

                int newChanged = changed;

            
                if(i == 2 || i == 5 || i == 6 || i == 9)
                    newChanged = 1;

                ans += solve(s, idx + 1, newTight, newChanged, 1);
            }
        }

        return dp[idx][tight][changed][started] = ans;
    }

    int rotatedDigits(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0, 0);
    }
};



//solution 2 brute force
class Solution {
public:
    unordered_map<int,int> dig = {
    {0,0},
    {1,1},
    {2,5},
    {5,2},
    {6,9},
    {8,8},
    {9,6}
};
    int rotatedDigits(int n) {
        
        int ans=0;
        for(int i=1;i<=n;i++){
           bool isans=true,issame=true;
           int nums=i;
           while(nums){
            int ld=nums%10;
            if(ld==3|| ld==4|| ld==7) {isans=false;break;}
             if(ld!=dig[ld]) issame=false;
             nums/=10;
           }
           if(isans && !issame) ans++;
        }
        return ans;
    }
};
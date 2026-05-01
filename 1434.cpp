class Solution {
    public:
    
        int mod = 1e9+7;
        vector<vector<int>> people;
        int dp[41][1<<10];
    
        int solve(int hat,int mask,int n){
    
            if(mask == (1<<n)-1)
                return 1;
    
            if(hat > 40)
                return 0;
    
            if(dp[hat][mask] != -1)
                return dp[hat][mask];
    
            long long ans = solve(hat+1,mask,n);
    
            for(int p:people[hat]){
                if(!(mask&(1<<p))){
                    ans += solve(hat+1,mask|(1<<p),n);
                }
            }
    
            return dp[hat][mask] = ans%mod;
        }
    
        int numberWays(vector<vector<int>>& hats) {
    
            int n = hats.size();
    
            people.assign(41,{});
    
            for(int i=0;i<n;i++){
                for(int h:hats[i]){
                    people[h].push_back(i);
                }
            }
    
            memset(dp,-1,sizeof(dp));
    
            return solve(1,0,n);
        }
    };
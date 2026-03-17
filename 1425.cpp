class Solution {
    public:
        int n;
        vector<int> dp;
    
        int solve(vector<int>& nums, int i, int k) {
            if (i >= n) return 0;
    
            if (dp[i] != INT_MIN) return dp[i];
    
            int best = 0;
    
            for (int j = i + 1; j <= min(n - 1, i + k); j++) {
                best = max(best, solve(nums, j, k));
            }
    
            return dp[i] = nums[i] + best;
        }
    
        int constrainedSubsetSum(vector<int>& nums, int k) {
            n = nums.size();
            dp.assign(n, INT_MIN);
    
            int ans = INT_MIN;
    
            for (int i = 0; i < n; i++) {
                ans = max(ans, solve(nums, i, k));
            }
    
            return ans;
        }
    };

    //ye bhut op question he isme  o(n*k) tc ati he jisme wo tle de deta he isliye humne monotonique deque use liya jis se k chekc min o(1) me aa gaya jis se ki overall o(n) me hard  solution ho gyaa approach ye he ki pichle k elements ka max dp sum jayega dp i me or is prblm me hum new st bhi kr skte he at every i so hum max le lenge prv k choice max and current nums i max dono me se jo max hoga wo dp i pr fit bethega overalll ans max of dp array

    class Solution {
        public:
            int constrainedSubsetSum(vector<int>& nums, int k) {
                int n=nums.size();
                int ans=nums[0];
                deque<int>dq;
                int dp[n];
                dp[0]=ans;
                dq.push_back(0);
        
                for(int i=1;i<n;i++){
        
                    while(dq.size() && dq.front()<i-k) dq.pop_front();
        
                    dp[i]=nums[i]+dp[dq.front()];
                    dp[i]=max(dp[i],nums[i]);
                    ans=max(ans,dp[i]);
        
                    while(dq.size() && dp[dq.back()]<dp[i]) dq.pop_back();
        
                    dq.push_back(i);
        
                }
          
             return ans;
        
            }
        };
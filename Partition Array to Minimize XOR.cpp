//THe only logic here is take min(cost,max(xor,reccursion call))

class Solution {
    public:
        int dp[251][251];
        vector<int> pre;
    
        int help(vector<int>& nums, int k, int n, int i) {
            if(k == 0 && i == n) return 0;
            if(k == 0 || i == n) return INT_MAX;
    
            if(dp[i][k] != -1) return dp[i][k];
    
            int cost = INT_MAX;
    
            for(int cut = i; cut < n; cut++) {
                int val;
                if(i == 0) val = pre[cut];
                else val = pre[cut] ^ pre[i-1];
    
                int next = help(nums, k-1, n, cut+1);
                if(next == INT_MAX) continue;
    
                cost = min(cost, max(val, next));
            }
    
            return dp[i][k] = cost;
        }
    
        int minXor(vector<int>& nums, int k) {
            int n = nums.size();
            memset(dp, -1, sizeof(dp));
    
            pre.resize(n);
            pre[0] = nums[0];
            for(int i = 1; i < n; i++)
                pre[i] = nums[i] ^ pre[i-1];
    
            return help(nums, k, n, 0);
        }
    };
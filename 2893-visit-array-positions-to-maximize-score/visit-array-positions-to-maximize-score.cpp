class Solution {
public:
    long long dp[100005][2];
    bool vis[100005][2];

    long long solve(int idx, int lastParity, vector<int>& nums, int x) {
        if (idx == nums.size())
            return 0;

        if (vis[idx][lastParity])
            return dp[idx][lastParity];

        vis[idx][lastParity] = true;

      
        long long ans = solve(idx + 1, lastParity, nums, x);

       
        long long take = nums[idx];

        if ((nums[idx] & 1) != lastParity)
            take -= x;

        take += solve(idx + 1, nums[idx] & 1, nums, x);

        ans = max(ans, take);

        return dp[idx][lastParity] = ans;
    }

    long long maxScore(vector<int>& nums, int x) {
             memset(vis, 0, sizeof(vis));

      
        return nums[0] + solve(1, nums[0] & 1, nums, x);
    }
};
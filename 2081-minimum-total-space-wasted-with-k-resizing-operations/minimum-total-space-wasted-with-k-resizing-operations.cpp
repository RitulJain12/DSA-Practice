class Solution {
public:
    int dp[201][201];
    vector<int> pre;
    int n;

    int help(vector<int>& nums, int k, int idx) {

        if (idx == n)  return 0;

        if (dp[idx][k] != -1) return dp[idx][k];

        int mx = 0;
        int ans = INT_MAX;

        for (int j = idx; j < n; j++) {

            mx = max(mx, nums[j]);

            int sum = pre[j] - (idx ? pre[idx - 1] : 0);

            int waste = mx * (j - idx + 1) - sum;

            if (j == n - 1)   ans = min(ans, waste);
            
            else if (k > 0)    ans = min(ans, waste + help(nums, k - 1, j + 1));
            
        }

        return dp[idx][k] = ans;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {

        memset(dp, -1, sizeof(dp));

        n = nums.size();

        pre.resize(n);

        pre[0] = nums[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        return help(nums, k, 0);
    }
};
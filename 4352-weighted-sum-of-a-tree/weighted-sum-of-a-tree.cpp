class Solution {
public:

    long long help(vector<vector<int>>& tree,
                   int h,
                   int d,
                   vector<int>& nums,
                   int src) {

        long long ans = 1LL * nums[src] * (h - d + 1);

        for (auto &nei : tree[src]) {
            ans += help(tree, h, d + 1, nums, nei);
        }

        return ans;
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        int n = parent.size();

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

   
        int h = 0;

        function<void(int,int)> dfs = [&](int node, int depth) {

            h = max(h, depth);

            for (int child : tree[node]) {
                dfs(child, depth + 1);
            }
        };

        dfs(0, 1);

        return help(tree, h, 1, nums, 0);
    }
};
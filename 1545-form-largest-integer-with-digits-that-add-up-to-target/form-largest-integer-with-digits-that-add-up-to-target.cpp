class Solution {
public:
    vector<string> dp;
    vector<int> vis;

    string help(vector<int>& cost, int target) {
        if (target == 0) return "";
        if (target < 0) return "#";   

        if (vis[target]) return dp[target];
        vis[target] = 1;

        string ans = "#";

       
        for (int d = 8; d >= 0; d--) {
            string nxt = help(cost, target - cost[d]);

            if (nxt == "#") continue;

            string cur = char('1' + d) + nxt;

            if (ans == "#" ||
                cur.size() > ans.size() ||
                (cur.size() == ans.size() && cur > ans))
                ans = cur;
        }

        return dp[target] = ans;
    }

    string largestNumber(vector<int>& cost, int target) {
        dp.assign(target + 1, "");
        vis.assign(target + 1, 0);

        string ans = help(cost, target);

        return ans == "#" ? "0" : ans;
    }
};
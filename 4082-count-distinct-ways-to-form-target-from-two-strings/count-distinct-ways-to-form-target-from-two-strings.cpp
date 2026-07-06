
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[102][102][102];

    unordered_map<char, vector<int>> pos1, pos2;

    int n, m, tlen;

    int solve(int i, int j, int k,
              string &word1, string &word2, string &target) {

        if (k == tlen) return (i!=-1 && j!=-1);

        int &ans = dp[i + 1][j + 1][k];
        if (ans != -1) return ans;

        ans = 0;

        auto &v1 = pos1[target[k]];
        auto it1 = upper_bound(v1.begin(), v1.end(), i);

        while (it1 != v1.end()) {
            ans = (ans + solve(*it1, j, k + 1,
                               word1, word2, target)) % MOD;
            ++it1;
        }
        auto &v2 = pos2[target[k]];
        auto it2 = upper_bound(v2.begin(), v2.end(), j);

        while (it2 != v2.end()) {
            ans = (ans + solve(i, *it2, k + 1,
                               word1, word2, target)) % MOD;
            ++it2;
        }

        return ans;
    }

    int interleaveCharacters(string word1, string word2, string target) {

        memset(dp, -1, sizeof(dp));

        n = word1.size();
        m = word2.size();
        tlen = target.size();

        for (int i = 0; i < n; i++)
            pos1[word1[i]].push_back(i);

        for (int i = 0; i < m; i++)
            pos2[word2[i]].push_back(i);

        return solve(-1, -1, 0, word1, word2, target);
    }
};
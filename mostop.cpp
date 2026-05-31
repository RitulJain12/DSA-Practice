
//it is a question of leetcode 1125. whichh unlocks the concept of  taking the values that are in ans with the help of the choice array and we can find the answer by just taking the values of the choice array and we can find the answer by just taking the values of the choice array and we can find the answer by just taking the values of the choice array and we can find the answer by just taking the values of the choice array.
class Solution {
public:
    int dp[61][1 << 16];
    bool choice[61][1 << 16];
    vector<int> personMask;
    int n, m;
    int fullMask;
    int solve(int idx, int mask) {

        if (mask == fullMask) return 0;

        if (idx == n) return 1e9;

        if (dp[idx][mask] != -1)  return dp[idx][mask];

        int skip = solve(idx + 1, mask);

        int pick = 1 + solve(idx + 1,  mask | personMask[idx]);

        if (pick < skip) {
            choice[idx][mask] = true;
            return dp[idx][mask] = pick;
        }

        choice[idx][mask] = false;
        return dp[idx][mask] = skip;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills,   vector<vector<string>>& people) {

        m = req_skills.size();
        n = people.size();

        fullMask = (1 << m) - 1;

        unordered_map<string, int> skillId;

        for (int i = 0; i < m; i++) {
            skillId[req_skills[i]] = i;
        }

        personMask.resize(n);

        for (int i = 0; i < n; i++) {

            int mask = 0;

            for (auto &skill : people[i]) {
                mask |= (1 << skillId[skill]);
            }

            personMask[i] = mask;
        }

        memset(dp, -1, sizeof(dp));

        solve(0, 0);
        vector<int>ans;
        int msk=0;
        for(int i=0;i<n;i++){
            if(choice[i][msk]==1){
                ans.push_back(i);
                msk |=personMask[i];
            }
        }

        return ans;
    }
};
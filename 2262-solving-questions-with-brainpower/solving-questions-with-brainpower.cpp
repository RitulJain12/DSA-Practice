class Solution {
public:
     long long dp[100001];

     long long help(int idx,vector<vector<int>>& q)
     {

        if(idx>=q.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        long long ans=0;

        ans=help(idx+1,q);

        ans=max(ans,q[idx][0]+help(idx+q[idx][1]+1,q));


        return dp[idx]=ans;

     }

    long long mostPoints(vector<vector<int>>& questions) {

        memset(dp,-1,sizeof(dp));

        return help(0,questions);
        
    }
};
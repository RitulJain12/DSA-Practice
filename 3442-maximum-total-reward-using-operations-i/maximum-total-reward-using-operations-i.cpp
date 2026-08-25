class Solution {
public:
     int dp[2001][4002];
    int help(int idx,int sc,int &n,vector<int>& re){
         if(idx>=n) return sc;
         if(dp[idx][sc]!=-1) return dp[idx][sc];

         int pick=0,np=0;

         np=help(idx+1,sc,n,re);

         if(re[idx]>sc) pick=help(idx+1,sc+re[idx],n,re);


         return dp[idx][sc]=max(pick,np);

    }
    int maxTotalReward(vector<int>& rewardValues) {
        memset(dp,-1,sizeof(dp));
        int n=rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        return help(0,0,n,rewardValues);
    }
};
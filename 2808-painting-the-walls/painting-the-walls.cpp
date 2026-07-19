class Solution {
public:
    int dp [501][504];
    int help(int idx,int sum,int &t,vector<int>& cost, vector<int>& time)
    {
        if(sum>=cost.size()) return 0;
        if(idx>=cost.size()){
           if(sum>=cost.size()) return 0;
           return INT_MAX;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        int ans=INT_MAX;
        ans= help(idx+1,sum+time[idx]+1,t,cost,time);

        if(ans!=INT_MAX) ans+=cost[idx];
        
        ans=min(ans,help(idx+1,sum,t,cost,time));


        return dp[idx][sum]=ans;

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {

        memset(dp,-1,sizeof(dp));
        int t=accumulate(time.begin(),time.end(),0);

        return help(0,0,t,cost,time);
        
    }
};
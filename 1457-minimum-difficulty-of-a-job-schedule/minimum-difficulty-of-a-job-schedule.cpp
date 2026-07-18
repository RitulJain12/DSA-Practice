class Solution {
public:
     int dp[301][11];
     int help(int idx,int d,vector<int>& job)
     { 

        if(idx==job.size()){
            if(d==0) return 0;
            return INT_MAX;
        }
        if(d==0) return INT_MAX;
        if(dp[idx][d]!=-1) return dp[idx][d];
         int ans=INT_MAX;
         int maxi=job[idx];
        for(int i=idx;i<job.size();i++){
           maxi=max(maxi,job[i]);
           int a=help(i+1,d-1,job);

            if(a!=INT_MAX) ans=min(ans,maxi+a);

        }


        return dp[idx][d]=ans;

     }
    int minDifficulty(vector<int>& j, int d) {

        memset(dp,-1,sizeof(dp));


        int a= help(0,d,j);
        if(a==INT_MAX) return -1;

        return a;
        
    }
};
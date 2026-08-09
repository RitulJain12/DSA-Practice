class Solution {
public:
     int dp[100001][28];
    int help(int idx,int prv,int &n,int &k,string &s){

       if(idx>=n) return 0;
       if(dp[idx][prv]!=-1) return dp[idx][prv];

       int skip=help(idx+1,prv,n,k,s);

       int cost=abs(prv+97-s[idx]);
        
    int pick=0;
    if(prv==27 || cost<=k) pick=1+help(idx+1,s[idx]-97,n,k,s);

     return dp[idx][prv]=max(pick,skip);

    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
          int n=s.size();
        return help(0,27,n,k,s);
    }
};
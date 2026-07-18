class Solution {
public:

     int dp[101][101];
        int getLen(int cnt) {
        if (cnt == 1) return 1;
        if (cnt < 10) return 2;
        if (cnt < 100) return 3;
        return 4;
    }
     int help(string &s, int k,int idx)
     {
         if(k<0) return 1e9;
        if(idx>=s.size()) return 0;
       
        if(dp[idx][k]!=-1) return dp[idx][k];

          int ans=0;

         ans=help(s,k-1,idx+1);

        int same=0,delt=0;
         for(int i=idx;i<s.size();i++){
            if(s[i]==s[idx]) same++;
            else delt++;
            if(delt>k)  break;
            ans=min(ans,getLen(same)+help(s,k-delt,i+1));
         }
        return dp[idx][k]=ans;
     }
    int getLengthOfOptimalCompression(string s, int k) {

        int n=s.size();

        memset(dp,-1,sizeof(dp));

        return help(s,k,0);
    }
};
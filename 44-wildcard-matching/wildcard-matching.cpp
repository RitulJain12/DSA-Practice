class Solution {
public:
    int8_t dp[2001][2001];
    int help(string &s, string &p,int i,int j)
    {

        if(i==s.size()){
            while(j<p.size() && p[j]=='*') j++;
            return j==p.size();
        }
          if(j==p.size()) return 0;       
        if(dp[i][j]!=-1) return dp[i][j];

        bool matched=false;
        if(s[i]==p[j])matched=help(s,p,i+1,j+1);
        else if(p[j]=='?') matched=help(s,p,i+1,j+1);
        else if(p[j]=='*'){
            bool keepstar=help(s,p,i+1,j);
            bool empty=help(s,p,i,j+1);
            matched=help(s,p,i+1,j+1);
           matched=  matched||keepstar;
           matched=matched||empty;
        }
        return dp[i][j]= matched;
    }

    bool isMatch(string s, string p) {

        memset(dp,-1,sizeof(dp));

        return help(s,p,0,0);
        
    }
};
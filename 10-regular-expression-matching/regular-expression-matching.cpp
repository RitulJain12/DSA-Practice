class Solution {
public:
    int8_t dp[21][21];
    int help(int i,int j,string &s,string &p)
    {

   if(j==p.size())
    return i==s.size();

if(dp[i][j]!=-1)
    return dp[i][j];

bool first =
    i<s.size() &&
    (s[i]==p[j] || p[j]=='.');

if(j+1<p.size() && p[j+1]=='*')
{
    return dp[i][j] =
        help(i,j+2,s,p) ||
        (first && help(i+1,j,s,p));
}

return dp[i][j] =
    first && help(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) 
    {
        int n=s.size();
         memset(dp,-1,sizeof(dp));
        return help(0,0,s,p);
    }
};
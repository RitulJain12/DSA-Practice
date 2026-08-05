class Solution {
public:
     unordered_map<string,bool>dp;
     bool help(string s1, string s2)
     {

        if(s1==s2) return 1;
        if(s1.size()!=s2.size()) return 0;
        auto key=s1+"-"+s2;
        if(dp.contains(key)) return dp[key];
        int n=s1.size();
        bool ans=0;
        for(int i=1;i<n;i++)
        {
       
           bool ns=help(s1.substr(0,i),s2.substr(0,i)) && help(s1.substr(i,n-i),s2.substr(i,n-1));

           bool s=help(s1.substr(i,n-i),s2.substr(0,n-i)) && help(s1.substr(0,i),s2.substr(n-i,i));

           ans|=(s||ns);
        
        }
        return dp[key]=ans;
     }
    bool isScramble(string s1, string s2) {
    
    return help(s1,s2);

    }
};
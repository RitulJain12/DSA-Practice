class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string copy=s;
        unordered_map<int,int>mp;
        for(char c:s) mp[c]++;
        sort(copy.begin(),copy.end());
         if(copy==s) return 0;
        if(s[0]==copy[0]|| s[n-1]==copy[n-1]) return 1;
       
        if(n==2 && s[0]>s[n-1]) return -1;
        if(s[0]==copy[n-1] && s[n-1]==copy[0] && mp[s[0]]==1 && mp[s[n-1]]==1 ) return 3;
        return 2;
    }
};
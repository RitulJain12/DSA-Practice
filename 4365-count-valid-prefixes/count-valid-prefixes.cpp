class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();

        int ans=0;
        int o=0,z=0;
        for(int i=0;i<n;i++){

            if(s[i]=='0') z++;
            else o++;

            if(abs(z-o)==1 || abs(z-o)==0) ans++;

        }
        return ans;
    }
};
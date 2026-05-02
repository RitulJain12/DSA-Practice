class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        int ans=INT_MAX, left=0;
        for(int i=0;i<n;i++){
        left = min(left+(s[i]-'0')*2,i+1);
         ans=min(ans,left+n-i-1);
        }

        return ans;
    }
};
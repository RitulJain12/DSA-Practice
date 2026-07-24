class Solution {
public:
    int dp[3][1001];
    int help(int e,int f)
    {
        if(e==1) return f;
        if(f==0 || f==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=INT_MAX;
        int l=1,h=f;
        while(l<=h){
            int mid=l+(h-l)/2;
            int brk=help(e-1,mid-1);
            int ntbrk=help(e,f-mid);

            ans=min(ans,1+max(brk,ntbrk));
            if(brk<ntbrk) l=mid+1;
            else h=mid-1;
        }

        return dp[e][f]=ans;

    }
    int twoEggDrop(int n) {
        
        memset(dp,-1,sizeof(dp));

        return help(2,n);

    }
};
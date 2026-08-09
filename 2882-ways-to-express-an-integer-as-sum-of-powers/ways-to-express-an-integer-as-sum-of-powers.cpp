class Solution {
public:
  int findK(int n, int x) {
    int lo = 1, hi = n;
    int ans = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;

        long long p = 1;

        for (int i = 0; i < x; i++) {
            p *= mid;

            if (p > n)
                break;
        }

        if (p <= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}
    int dp[301][301];
    int coff;
    int help(int idx,int n,int &last)
    {   
        if(n==0) return 1;
        if(idx>last) return 0;

        if(dp[idx][n]!=-1) return dp[idx][n];

        int ans=0;

        ans=(ans+help(idx+1,n,last))%1000000007;

        long long cost=pow(idx,coff);

       if(n-cost>=0)  ans=(ans+help(idx+1,n-cost,last))%1000000007;
       
        return dp[idx][n]=ans;
    }
    int numberOfWays(int n, int x) {
        
        int lowerval=findK(n,x);
        coff=x;
        memset(dp,-1,sizeof(dp));

         return help(1,n,lowerval);

    }
};
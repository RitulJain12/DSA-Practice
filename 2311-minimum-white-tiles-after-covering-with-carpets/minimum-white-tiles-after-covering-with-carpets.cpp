class Solution {
public:
    int dp[1001][1001];
    vector<int>nxt;
    int help(int idx,int k,int &l,string &f)
    {
       
        if(idx>=f.size()) return 0;
         if(k==0) return nxt[idx];

        if(dp[idx][k]!=-1) return dp[idx][k];

        int ans=INT_MAX;
        int cost=  f[idx]=='1'?1:0;

        ans=cost+help(idx+1,k,l,f);

        ans=min(ans,help(idx+l,k-1,l,f));


        return dp[idx][k]=ans;

    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {

        memset(dp,-1,sizeof(dp));
        int n=floor.size();
         nxt.resize(n,0);
         nxt[n-1]=floor[n-1]=='1'?1:0;
         for(int i=n-2;i>=0;i--){

              int cost=floor[i]=='1';

              nxt[i]=cost+nxt[i+1];
            
         }
        return help(0, numCarpets, carpetLen,floor);
        
    }
};
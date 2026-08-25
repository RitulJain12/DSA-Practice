class Solution {
public:
    int dp[100001];
    bool help(int n){
         
           if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
      
        int k=sqrt(n);
      
        
        for(int i=1;i<=k;i++){

            int rem=n-i*i;

            if(!help(rem))  return dp[n]=true;
        }


        return dp[n]=0;


    }
    bool winnerSquareGame(int n) {
        int k=sqrt(n);

        memset(dp,-1,sizeof(dp));


        return help(n);

    }
};
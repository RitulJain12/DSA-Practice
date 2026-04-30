class Solution {
    public:
        int dp[24][2][402];
        const int mod=1e9+7;
        int solve(string &s,int tight,int idx,int sum,int &min_sum,int &max_sum){
    
            if(idx==s.size()) {
                return (sum>=min_sum && sum<=max_sum);
            }
            if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
            int lmt=(tight==1)?s[idx]-'0':9;
            int ans=0;
            for(int i=0;i<=lmt;i++){
               
              if(sum+i<=400){
                ans=(ans+solve(s,tight &(s[idx]-'0'==i),idx+1,sum+i,min_sum,max_sum)%mod)%mod;
              }
            }
            return dp[idx][tight][sum]=ans;
        }
        int count(string num1, string num2, int min_sum, int max_sum) {
                memset(dp,-1,sizeof(dp));
            int rght=solve(num2,1,0,0,min_sum,max_sum);
             memset(dp,-1,sizeof(dp));
             int left=solve(num1,1,0,0,min_sum,max_sum);
    
             int leftcase=0,i=0;
             while(i<num1.size()) leftcase+=num1[i++]-'0';
             if(leftcase>=min_sum && leftcase<=max_sum)    return ( (rght - left+1 + mod) % mod );
             return ( (rght - left + mod) % mod );
        }
    };
class Solution {
public:
        int gcd(int x,int y){
            if(y==0) return x;
            return gcd(y, x % y);
        }
        int dp[1<<14];
        int help(int idx,vector<int>& nums,int mask){
            int n=nums.size();
            if(mask==(1<<nums.size())-1) return 0;
          
            if(dp[mask]!=-1) return dp[mask];

            int ans=0;

            int cnt=__builtin_popcount(mask)/2 +1;

            for(int i=0;i<n;i++){

                  if(mask  & (1<<i)) continue;
                
                for(int j=i+1;j<n;j++){
                  
                 if(mask  & (1<<j)) continue;

                     if(!(mask & (1<<i) ||  mask & (1<<j))){
                        int newmask=mask | (1<<i);
                        newmask|=(1<<j);
                        ans=max(ans,(cnt)*gcd(nums[i],nums[j])+help(idx+1,nums,newmask));
                     }
                }
            }

            return dp[mask]=ans;
   
        }
        int maxScore(vector<int>& nums) {
            memset(dp,-1,sizeof(dp));

            return help(0,nums,0);
        }
};
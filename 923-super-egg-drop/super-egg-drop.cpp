class Solution {
public:
      
      int dp[101][10001];

      int help(int egg,int floor)
      {
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
       
        if(dp[egg][floor]!=-1) return dp[egg][floor];

        int ans=INT_MAX;

          int low=1,h=floor;
          while(low<=h){

           int mid=low+(h-low)/2;
              
          int brk=help(egg-1,mid-1);
          int ntbrk=help(egg,floor-mid);

        
             ans = min(ans, 1 + max(brk, ntbrk));

            if (brk < ntbrk) {
                low = mid + 1;
            } else {
                h = mid - 1;
            }
          }

         return dp[egg][floor]= ans;
      }
    int superEggDrop(int k, int n) {

        memset(dp,-1,sizeof(dp));
        return help(k,n);
      
    }
};
class Solution {
public:
     int dp[1001][1002][2];
    int help(int i,int prv,int sign,vector<int>&nums)
    {
       
       if(i==nums.size()) return 0;
       if(dp[i][prv+1][sign]!=-1) return dp[i][prv+1][sign];

       int ans=0;

       ans=help(i+1,prv,sign,nums);

       if(prv==-1) ans=max(ans,1+help(i+1,i,sign,nums));

      else  if(sign==0 && nums[i]-nums[prv]>0){
   
       ans=max(ans,1+help(i+1,i,1,nums)); 
         
       }
       else if(sign==1 && nums[i]-nums[prv]<0){
            ans=max(ans,1+help(i+1,i,0,nums)); 
    
       }


       return dp[i][prv+1][sign]=ans;

    }
    int wiggleMaxLength(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return 1;
        if(n==2 && nums[0]==nums[1]) return 1;
        if(n==2) return 2;

        memset(dp,-1,sizeof(dp));
      return max( help(0,-1,0,nums), help(0,-1,1,nums));
        
    }
};
class Solution {
public:
     int dp[1001];
     int help(int idx,vector<int>& nums, int &target){
        if(idx>=nums.size()-1)  return 0;
        if(dp[idx]!=-1) return dp[idx];

          int  ans=INT_MIN;
          for(int i=idx+1;i<nums.size();i++){

              if(abs(nums[idx]-nums[i])<=target)  {
                 ans=max(ans,1+help(i,nums,target));
              }

          }


          return dp[idx]=ans;

     }
    int maximumJumps(vector<int>& nums, int target) {


        memset(dp,-1,sizeof(dp));

        int a= help(0,nums,target);

        cout<<a;

        if(a<0) return  -1;

        return  a;


    }
};
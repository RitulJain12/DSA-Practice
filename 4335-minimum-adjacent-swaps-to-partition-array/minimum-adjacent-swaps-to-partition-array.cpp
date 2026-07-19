class Solution {
public:
    int MOD=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b)
    {
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
         
         if(nums[i]<a) nums[i]=0;
         else if(nums[i]>=a && nums[i]<=b) nums[i]=1;
         else nums[i]=2;
      }    

       int ans=0;

       int one=0,two=0,zero=0;

         for(int i=0;i<nums.size();i++){

              if(nums[i]==0){

                zero++;

                ans=(ans+one)%MOD;
                ans=(ans+two)%MOD;

              }

              else if (nums[i]==1){

                 one++;

             //   ans=(ans+one)%MOD;
                ans=(ans+two)%MOD;

              }
              else two++;
         }


         return ans;
       
    }
};
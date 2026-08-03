class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n=nums.size();

          int ans=0;

          for(int i=0;i<n;i++){
              int o=0,e=0;
              if(nums[i]%2) o++;
              else e++;
            if(o>0  && e*1LL*b<=o*1LL*a) ans++;
              for(int j=i+1;j<n;j++){
               if(nums[j]%2) o++;
               else e++;
                 if(o>0  && e*1LL*b<=o*1LL*a) ans++;
              
              }

          }


          return ans;
        
    }
};
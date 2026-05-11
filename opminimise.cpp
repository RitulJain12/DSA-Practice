class Solution {
public:
    long long minArraySum(vector<int>& nums) {
         int n=nums.size();
         int mx = *max_element(nums.begin(), nums.end());
         int min = *min_element(nums.begin(), nums.end());
         long long sum=accumulate(nums.begin(), nums.end(),0LL);
         vector<int>maxi(mx+1,0);
         if(min==1) return n;

           for(auto & x:nums) maxi[x]++;

           for(int i=0;i<=mx;i++){
             
             if(maxi[i]==0) continue;

              for(int j=i*2;j<=mx;j+=i){
                  if(maxi[j]>0){
                       sum-=maxi[j]*1LL*j;
                       sum+=maxi[j]*1LL*i;
                       maxi[j]=0;
                  }
              }

           }

           return sum;

    }
};
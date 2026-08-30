class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN, mini=INT_MAX;
        int maxidx=0,minidx=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
         if(nums[i]>maxi) {
          maxi=nums[i];
          maxidx=i;
            }
             if(nums[i]<mini) {
          mini=nums[i];
          minidx=i;
            }
        }
      if(minidx>maxidx) swap(minidx,maxidx);
      int ans1=maxidx+1;
      int ans2=n-minidx;
      int ans3= minidx+1+n-maxidx;
      return min({ans1,ans2,ans3});

    }
};
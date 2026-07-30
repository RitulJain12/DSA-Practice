class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();
        vector<int>p(n,-1);
        sort(nums.begin(),nums.end());

        vector<int>LDS(n,1);
           int maxi=0,indx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if( nums[i]%nums[j]==0 && LDS[i]<1+LDS[j]){
                    LDS[i]=1+LDS[j];
                    p[i]=j;
                }
            }
            if(maxi<LDS[i]){
                maxi=LDS[i];
                indx=i;
            }
        }
   vector<int>ans;

   while(indx!=-1){
      ans.push_back(nums[indx]);
      indx=p[indx];
   }

        return ans;
    }
};
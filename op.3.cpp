class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

       int cnt=0;
       int n=nums.size();

         for(int i=0;i<n;i++){
            
            if(nums[i]>nums[i+1]){
            
                if(i>0 && nums[i+1]>=nums[i-1]) nums[i]=nums[i+1];

                else if(i==0) nums[i]=nums[i+1];


                else nums[i+1]=nums[i];


               cnt++;


            }

            if(cnt>1) return 0;

         }
    }
};
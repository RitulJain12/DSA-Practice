class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int pivot=0;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=nums[0]) l=mid+1;
            else{
                pivot=mid;
                h=mid-1;
            }
        }
        return nums[pivot];
    }
};
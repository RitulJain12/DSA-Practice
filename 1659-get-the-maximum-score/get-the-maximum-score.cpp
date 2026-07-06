class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();
        long long  i=0,j=0,px=0,py=0,cx=0,cy=0;
        int mod=1e9+7;

         while(i<n && j<m){
            if(nums1[i]<nums2[j]) cx+=nums1[i++];
            else if(nums1[i]>nums2[j]) cy+=nums2[j++];
            else cx=cy=max(px+nums1[i++],py+nums2[j++]);
            px=cx;
            py=cy;

         }
        while (i < n) cx+= nums1[i++];
        while (j < m) cy += nums2[j++];
        return max(cx,cy)%mod;
    }
};
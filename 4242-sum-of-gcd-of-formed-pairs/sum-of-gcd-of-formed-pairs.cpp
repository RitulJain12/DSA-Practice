class Solution {
public:
    int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pre[i]=gcd(nums[i],maxi);
        }
        sort(pre.begin(),pre.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j){
             ans+=gcd(pre[i++],pre[j--]);
        }
        return ans;
    }
};
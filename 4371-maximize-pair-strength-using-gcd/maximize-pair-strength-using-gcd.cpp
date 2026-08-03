class Solution {
public:
 int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a % b); 
}
    long long maxPairStrength(vector<int>& nums) {

        long long ans=0;

        int n=nums.size();

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                 ans=max(ans,(nums[i]*1LL*nums[j])/(gcd(nums[i],nums[j])*1LL*gcd(nums[i],nums[j])));
            }

        }
        return ans;
    }
};
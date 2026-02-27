//it is question like a hell bro
class Solution {
    public:
        long long gcd(long long a,long long b){
            if(b==0) return a;
    
            return gcd(b,a%b);
    
        }
        long long lcm(long long a,long long b){
            return a*b/(gcd(a,b));
        }
        long long can(vector<int>& coins, long long &mid){
            int m=coins.size();
            int allones=(1<<m)-1;
            long long cnt=0;
            for(int mask=1;mask<=allones;mask++){
                long long setBitslcm=1;
                for(int i=0;i<m;i++){
                    if(mask & (1<<i)) setBitslcm= lcm(setBitslcm,coins[i]);
    
                }
    
                if(__builtin_popcount(mask) & 1) cnt+=mid/setBitslcm;
                else cnt-=mid/setBitslcm;
    
            }
    
            return cnt;
        }
        long long findKthSmallest(vector<int>& coins, int k) {
            int n=coins.size();
            long long l=k,h = 1LL * (*min_element(coins.begin(),coins.end())) * k;
            long long ans=0;
            while(l<=h){
                long long mid=l+(h-l)/2;
                if(can(coins,mid)>=k) {
                    ans=mid;
                    h=mid-1;
                }
                else l=mid+1;
            }
            return ans;
        }
    };
    //isse ye sikhne ko mila ki permutations kaise banate he hum saree elements ki bitwise mask k sath bss phir permutations banakr hr permutation pr o to n check kra jo bit on thi uska lcm lete gaye final agr count odd he tph + else - 
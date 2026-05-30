//we can find that in n how much element have power k by just fiding the largest x for which x^k<=n and then we can find the answer by just doing n/x^k and we can do this for all k from 1 to log(n) and we can find the answer by just adding all the answers for all k from 1 to log(n)

// for example let take  k=2 we know that the largest x for which x*x<=30 is 5  so there are 5 number from 0 to 5 that have power 2 less than or equal to 30 that are 1,2,3,4,5

class Solution {
public:
    bool can(long long mid,int k,long long n)
    {
        long long ans=1;

        if(mid==0) return true;

        for(int i=0;i<k;i++){
            if(ans>n/mid) return false;
            ans*=mid;
        }
        return ans<=n;
    }
    long long  take(long long n,int k){

        long long l=0,h=n;
        long  long mid=0,ans=0;

        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(can(mid,k,n)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

        return ans;

    }
    int countKthRoots(int l, int r, int k) {


      long long ri=take(r,k);
      long long li = (l == 0 ? 0 : take((long long)l - 1, k));
      int ans=ri-li;
      if(l==0) ans++;
    
        
       return(int) ans;
    }
};
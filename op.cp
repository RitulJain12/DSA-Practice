class Solution {
public:
   bool can(long long mid, vector<int>& d, vector<int>& r) {
     long long l=lcm(r[0],r[1]);
     long long only1=mid/r[1]-mid/l;
     long long only2=mid/r[0]-mid/l;
     long long both=mid-mid/r[0]-mid/r[1]+mid/l;

     long long n1=max(0LL,(d[0]-only1));
     long long n2=max(0LL,(d[1]-only2));

     return n1+n2<=both;
}
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long l=d[0]+d[1];
        long long h=d[0]*1LL*r[0]+d[1]*1LL*r[1];
        long long ans=0;
        while(l<=h){

            long long mid=l+(h-l)/2;

            if(can(mid,d,r)){
                ans=mid;
                h=mid-1;
            }
          else l=mid+1;
        }

        return ans;
    }
};
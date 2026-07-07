class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
               if(buckets==1) return 0;
             long long res=minutesToTest/minutesToDie +1;
             int pig=1;
             long long ans=res;
          for(int i=0;ans<buckets;i++ ){
              ans*=res;
              pig++;
          }
          return pig;
    }
};
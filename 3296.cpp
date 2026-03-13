// BHai yye question kya question tha yrr solved by me in 39 minutes with all direction without even knowing hints pure maths approach or  wo formula wala toh kya hi mst tha
class Solution {
    public:
        bool can(int mountainHeight, vector<int>& w,long long &mid){
    
           for(int i=0;i<w.size();i++){
            //  long long n=1;
            if(w[i]>mid) continue;
            long long X = (2 * mid) / w[i];
             long long n = (sqrt(1 + 4 * X) - 1) / 2;
           mountainHeight -=n;
           if(mountainHeight <=0) return true;
           }
    
           return mountainHeight <=0;
        }
        long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
            
        long long l=1;
        long long mx = *max_element(workerTimes.begin(), workerTimes.end());
        long long h = mx * (1LL * mountainHeight * (mountainHeight + 1) / 2);
    
          long long ans=0;
            while(l<=h){
                long long mid=l+(h-l)/2;
                if(can(mountainHeight,workerTimes,mid)) {
                    ans=mid;
                    h=mid-1;
                }
              else   l=mid+1;
            }
    
            return ans;
        }
    };
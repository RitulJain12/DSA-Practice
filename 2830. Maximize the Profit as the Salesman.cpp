class Solution {
    public:
         int dp[100001];
     int next(vector<vector<int>>& offers,int val,int l){
        int h=offers.size()-1;
         int idx=offers.size();
    
          while(l<=h){
                int mid=l+(h-l)/2;
             if(offers[mid][0]>val){
                idx=mid;
                h=mid-1;
             }
             else l=mid+1;
          }
    
          return idx;
           
     }
        int helper(int i,vector<vector<int>>& offers){
               if(i==offers.size()) return 0;
               if(dp[i]!=-1) return dp[i];
    
               int skip=helper(i+1,offers);
    
                    int a = offers[i][0];
                    int b = offers[i][1];
                    int c = offers[i][2];
                 int idx=next(offers,b,i);
                 //if(idx==-1) return 0;
    
               int pick= c+helper(idx,offers);
                
                return dp[i]=max(pick,skip);
        }
        int maximizeTheProfit(int n, vector<vector<int>>& offers) {
             
                 sort(offers.begin(),offers.end(),[&](auto a ,auto b){
                    if(a[0]==b[0]) return a[1]<b[1];
                    return a[0]<b[0];
                 });
               memset(dp,-1,sizeof(dp));
             
               return   helper(0,offers);
        }
    };
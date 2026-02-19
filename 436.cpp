//seems to be very easy but good question at the end
class Solution {
    public:
         int helper(vector<vector<int>>& intervals,int tar){
            int l=0,h=intervals.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(intervals[mid][0]==tar) return mid;
                else if(intervals[mid][0]<tar) l=mid+1;
                else h=mid-1; 
            }
             if(l>=intervals.size()) return -1;
            return l;
    
         }
        vector<int> findRightInterval(vector<vector<int>>& intervals) {
             unordered_map<int,int>mp;
             for(int i=0;i<intervals.size();i++) mp[intervals[i][0]]=i;
             sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
                 return a[0]<b[0];
             });
             vector<int>ans(intervals.size(),-1);
                  int n=intervals.size();
                
              //  ans[mp[intervals[n-1][0]]]=-1;
                
                for(int i=0;i<n;i++){
                
                 int tar=intervals[i][1];
                  int val=helper(intervals,tar);
                  if(val==-1) ans[mp[intervals[i][0]]]=-1;
                  else ans[mp[intervals[i][0]]]=mp[intervals[val][0]];
                }
                  return ans;
          } 
    };
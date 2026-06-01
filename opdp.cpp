class Solution {
public:
    int help(int idx,int k,vector<int>&nxt,vector<vector<int>>& events,  vector<vector<int>>&dp)
    {

        ///1751
       
         if(k==0) return 0;
         if(idx>=events.size()) return 0;

        //  auto key=make_pair(idx,k);

        //  if(dp.contains(key))  return dp[key];

        if(dp[idx][k]!=-1) return dp[idx][k];

         int skip=0+help(idx+1,k,nxt,events,dp);

        
       //  auto it=upper_bound(nxt.begin(),nxt.end(),nxtcan)-nxt.begin();
         int pick=events[idx][2]+help(nxt[idx],k-1,nxt,events,dp);

         return dp[idx][k]=max(pick,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {


        vector<int>nxt;
       sort(events.begin(),events.end());

       for(auto  &v:events) nxt.push_back(v[0]);
        int n=events.size();
       vector<int>nxtidx(n,0);

       for(int i=0;i<n;i++){
         auto it=upper_bound(nxt.begin(),nxt.end(),events[i][1])-nxt.begin();
         nxtidx[i]=it;
       }


      // memset(dp,-1,sizeof(dp));
      vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
      return help(0,k,nxtidx,events,dp);
        
    }
};
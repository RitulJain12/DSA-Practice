class Solution {
    public:
         int helper(int &n,vector<vector<int>>& requests,int i,unordered_map<int,int>&mp){
    
            if(i==requests.size()){
                if(!mp.size()) return 0;
                return INT_MIN;
            }
           
          //skip
          int skip=0+helper(n,requests,i+1,mp);
    
          //pick;
            mp[requests[i][1]]+=1;
            mp[requests[i][0]]-=1;
            if(mp[requests[i][0]]==0) mp.erase(requests[i][0]);
             if(mp[requests[i][1]]==0) mp.erase(requests[i][1]);
            int pick=helper(n,requests,i+1,mp);
            if(pick!=INT_MIN) pick+=1;
              mp[requests[i][1]]-=1;
              mp[requests[i][0]]+=1;
                if(mp[requests[i][0]]==0) mp.erase(requests[i][0]);
                if(mp[requests[i][1]]==0) mp.erase(requests[i][1]);   
            return max(skip,pick);
    
         }
        int maximumRequests(int n, vector<vector<int>>& requests) {
            unordered_map<int,int>mp;
            return helper(n,requests,0,mp);
        }
    };
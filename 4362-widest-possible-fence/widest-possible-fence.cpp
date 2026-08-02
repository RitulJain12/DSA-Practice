class Solution {
public:
    int maximumWidth(vector<int>& planks) {

      
        unordered_map<long long ,int> frq;
        for(auto &a:planks) frq[a]++;
        vector<pair<long long,int>>vp;
        for(auto &p:frq) vp.push_back(p);
    int n=vp.size();
          for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

              long long t=vp[i].first+vp[j].first;
              if(i==j) frq[t]+=vp[i].second/2;
              else frq[t]+=min(vp[i].second,vp[j].second);
            }
          }

          int ans=0;
          for(auto &p:frq) ans=max(ans,p.second);

          return ans;
        
    }
};
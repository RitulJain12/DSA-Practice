class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end(),[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
              return a[0]<b[0];
        });
          int ans=0;
          int maxdef=properties[n-1][1];
          for(int i=n-2;i>=0;i--){
              if(properties[i][1]<maxdef) ans++;
              maxdef=max(maxdef,properties[i][1]);
          }

          return ans;
    }
};
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
     {
          int n=firstList.size();
          int m=secondList.size();

          vector<vector<int>>ans;

          int i=0,j=0;

          while(i<n && j<m)
          {
             
            int& x = firstList[i][0];
            int& y = firstList[i][1];

            int& a = secondList[j][0];
            int& b = secondList[j][1];

             if(a>y || b<x) {
                if(y>b) j++;
                else i++;
                continue;
             }
             
             vector<int>v(2,0);

             v[0]=max(x,a);
             v[1]=min(y,b);
              if(y>b) j++;
                else i++;

             ans.push_back(v);

          }
        return ans;
    }
};
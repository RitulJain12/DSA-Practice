#include<bits/stdc++.h>
using namespace std;
// ye bhut mst pattern he deque ka jisme max value nikalni he humko ye question advance and achaa he isme equation he yi+yj+|xi-xj| ko max krna he and xi-xj<k hona chiye toh hum jab isko kholte he mod ko kyoki j>i hoga x is in sorted order toh eq hui yi+yj+xj-xi mtlb for i humko yi-xi rakhna he or xi<xj k liye xi bhi rakhna hoga queue me
class Solution {
    public:
        int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
            int n=points.size();
          long long ans = LLONG_MIN;
    
           deque<pair<long long,long long>> dq; 
            for(int i=0;i<n;i++){
          while(!dq.empty() && points[i][0] - dq.front().second > k)
        dq.pop_front();
    
           int temp=points[i][1]-points[i][0];
           int xcor=points[i][0];
           int ycor=points[i][1];
           int qfrnt=0;
           if(dq.size()) qfrnt=dq.front().first;
    
         if(!dq.empty()){
                 ans=max(ans,(long long)qfrnt+xcor+ycor);
         }
    
           
       while(dq.size() && dq.back().first<temp) dq.pop_back();
          dq.push_back({temp,xcor});
    
            }
    
    return ans;
        }
    };
    

int main(){


}
#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>>points={{1,3},{3,4},{2,5},{5,6},{7,8}};
    int n=points.size();
    int totalDistance=0;
    for(int i=1;i<n;i++){
        totalDistance+=max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
    }
    cout<<totalDistance<<endl;
    return 0;
}

// if we have to find the shortest  path from point a to point b then traverse along diagonal if possible otherwise move in x or y direction whichever is minimum
//   so take max of absolute difference of x coordinates and absolute difference of y coordinates of point a and point b
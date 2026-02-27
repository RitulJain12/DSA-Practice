#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<int> minRemain;
int can(vector<vector<int>> &mat,long long &mid,int i,int sum,int &k){

    if(i==m) return 1;
    if(i<n && sum+minRemain[i]>mid) return 0;
    int ans=0;

    for(int j=0;j<n;j++)
{
    if(sum+mat[i][j]>mid) break;
    ans+=can(mat,mid,i+1,sum+mat[i][j],k);
    if(ans>=k) return k;
}

return ans;

}
int main(){

    vector<vector<int>> mat = {
        {1, 50, 100, 150},
        {2, 60, 110, 160},
        {3, 70, 120, 170},
        {4, 80, 130, 180}
    };
int k=5;

m= mat.size(); n = mat[0].size();
minRemain.resize(m+1);
minRemain[m] = 0;


for(int i = m-1; i >= 0; i--) {
    minRemain[i] = minRemain[i+1] + mat[i][0];
}

long long l = 0, h = 0, ans = 0;

for(auto &row : mat) {
    l += row[0];
    h += row.back();
}

while(l <= h) {

    long long mid = l + (h-l)/2;

    if(can(mat, mid, 0, 0, k) >= k) {
        ans = mid;
        h = mid - 1;
    }
    else {
        l = mid + 1;
    }
}


cout<<ans<<endl;

return ans;






}


// ye ek number problem he bs on ans ki isme mko optimise krnee me bhut maja aya deep thi problem with lots of dry run  
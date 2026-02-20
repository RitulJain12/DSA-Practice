#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>&v){
 int n=v.back();

 while(n--){
    
    int ridx=rand()%v.back()+1;

    auto it=lower_bound(v.begin(),v.end(),ridx);

    int idx=it-v.begin();

    cout<<idx<<" "<<v[idx]<<endl;

 }

 return 0;
}
int main(){
    vector<int>v={1,3,6,10,15};
    helper(v);
}
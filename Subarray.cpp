/*
We can find the subarray of an array having xor with 32*n complexity as it do not having  diff vzalues greater than 32  for a int so worst case tc is 32*n which is good;the logic is only take 3 sets next, curr, and ans
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int>next,curr,ans;
    vector<int>arr={
        1,2,3,4,5
    };

    for(int i=0;i<arr.size();i++){
        next.clear();
        next.insert(arr[i]);

        for(auto val:curr) next.insert(val|arr[i]);
     curr=next;
          for(auto val:curr) ans.insert(val);

          
    }

    for(auto x:ans) cout<<x<<endl;
}
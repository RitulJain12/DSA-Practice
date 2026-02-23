#include<bits/stdc++.h>
using namespace std;
bool ISans(string &s,int k){
     int ans=pow(2,k);
     int n=s.size();
      unordered_set<string>st;
     for(int i=0;i<=n-k;i++){
        st.insert(s.substr(i,k));
        if(st.size()==ans){
            return true;
        }
     }

     return false;
}
int main()
{
    string s="0010";
    int k=2;
    cout<<ISans(s,k);
}
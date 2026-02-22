#include<bits/stdc++.h>
using namespace std;
int helper(string &s)
{
      int n=s.size();
      stack<char> st;
      st.push(-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
               st.pop();
               if(st.empty()) st.push(i);
               else ans=max(ans,i-st.top());
            }
        }
        return ans;
}
int main(){
string s="((())))))()()()()()((((()))))";
cout<<helper(s);
}
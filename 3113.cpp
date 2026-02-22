#include<bits/stdc++.h>
using namespace std;
int Helper(vector<int>& a){
    int n=a.size();
    stack<pair<int,int>> st;
    int ans=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first<a[i])    st.pop();
        if(!st.empty() &&  st.top().first==a[i]){
           ans+=st.top().second+1;
              st.top().second++;
        }
        else{
            st.push({a[i],1});
            ans++;
        }
        
    }
    return ans;
}
int main(){
    vector<int> a={3,1,3,1,3,3,3,3,1,5,5,2,4,25,6};
    int ans=Helper(a);
    cout<<ans<<endl;
    
}
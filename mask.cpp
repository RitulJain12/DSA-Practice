#include<bits/stdc++.h>
using namespace std;
void mask(string &str){
  int n=str.size();
  int allcomb=(1<<n)-1;
  for(int mask=1;mask<=allcomb;mask++){
       string ans="";
    for(int j=0;j<n;j++){
        if(mask & (1<<j))  ans.push_back(str[j]);
    }
    cout<<ans<<endl;
  }
}
int main()
{
    string str="abc";
    
     mask(str);

}
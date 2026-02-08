#include<bits/stdc++.h>
using namespace std;
int takeCharacters(string s, int k) {
   int ans=0;
   int n=s.length();
   unordered_map<char,int>mp;
   for(int i=0;i<n;i++) mp[s[i]]++;
   if(mp['a']<k||mp['b']<k||mp['c']<k) return -1;
   int reqa=mp['a']-k,reqb=mp['b']-k,reqc=mp['c']-k;
   //ye pattern he jisme humko left right se deletion krne ko hota he pr hum left right se min delete krne ki jagha max peak kr lete he take n-ans kree toh wo minimim ho jayega;
   mp.clear();
   int i=0,j=0;
   while(j<n){
       mp[s[j]]++;
       while (mp['a']>reqa||mp['b']>reqb || mp['c']>reqc)
       {
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(mp[s[i]]);
            i++;
       }

       ans=max(ans,j-i+1);
       
       j++;
   }
   return n-ans;
}
int main(){
    const string str="abcbabcbaccbabcbcbbabcbbcbacbbaaccbabcbacbabcabcabccbabcacbbbabcbabcbabc";
    int ans=takeCharacters(str,2);
    cout<<ans;
}
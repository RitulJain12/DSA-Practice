#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(string s) {
    int n=s.size();
    if(n==1) return 0;
    vector<int>a(n,0),b(n,0);
    int counta=0,countb=0, ans=INT_MAX;
    for(int i=0;i<n;i++) if(s[i]=='a') counta++;
    for(int i=0;i<n;i++){
        if(s[i]=='a')  counta--;
        a[i]=counta;
        b[i]=countb;
          if(s[i]=='b')  countb++;
        ans=min(ans,a[i]+b[i]);
    }
    return ans;
}
int main()
{

    string s ="aababababababaababababbababababbbaababababbbbababababbbab";

    int a=minimumDeletions(s);
    cout<<a<<endl;
}
//isme basically humko pura dimag laga kr bss ye pata krna tha ki hr index pr uske bad wale a dekh lo or phle walee b dekh lo jisse apko extra piche(i k piche) k b and i k aage k a pata chl jaynge dono ko hata skte ho ab hr i pr ja kr ye check kro or jiska sum minimum ho waha ye ans de dega

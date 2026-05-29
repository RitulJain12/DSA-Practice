//its a basic 2 var question but i solved it via pre suff array

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1=INT_MAX,n2=INT_MAX;
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
         if(n1<=arr[i]) n1=arr[i];
         else if(n2<=arr[i]) n2=arr[i];
        else cout<<"true";
    }
}
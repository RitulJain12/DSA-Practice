#include<bits/stdc++.h>
using namespace std;
int main(){

    //isme humko  ye dekhna hau ki  citetion of i se >= n-i papers hai ya  nahi  agar hai to iska matlab hai ki i papers kam se kam i citations ke sath hai aur baki n-i papers ke paas i citations se kam hai to iska matlab hai ki hume i hi return karna hai
    // aur humko maximum i return karna hai to hum binary search karenge i ke range me 0 se n tak aur har mid ke liye check karenge ki kya mid se zyada papers ke paas mid ya usse zyada citations hai ya nahi agar hai to iska matlab hai ki hume i ko badhana hai aur agar nahi to iska matlab hai ki hume i ko kam karna hai isme humko left side ja kr max ana banana he


    int n;
    cin>>n;
    int l=0,r=n;
    while(l<=r){    
        int mid=(l+r)/2;
        if(nums[mid]>=n-mid){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
  return ans;
}
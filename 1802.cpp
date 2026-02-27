#include<bits/stdc++.h>
using namespace std;
  bool can(int mid, int n, int index, int maxSum){
        long long sum=mid;
        long long left=index;
        long long right=n-index-1;
         if(mid-1>=left)sum+=(mid-1+mid-left)*left/2;
         else sum+=(mid-1+1)*mid/2+(left-mid+1);
         if(mid-1>=right)sum+=(mid-1+mid-right)*right/2;
         else sum+=(mid-1+1)*mid/2+(right-mid+1);
         
        return sum<=maxSum;
    }
int main(){
     int n, index, maxSum;
     cin >> n >> index >> maxSum;
        int low = 1, high = maxSum;
        int ans = 0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(can(mid, n, index, maxSum)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<ans;
     return 0;
}


// 1802 - Maximum Value at a Given Index in a Bounded Array is a bs on answer type question in which we have to effectively find ans without even creating the array explicitly.
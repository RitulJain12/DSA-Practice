//it is code of first thought principle in which we have to +k and -k and make two array equal so the two array can be equal if and only if the diff betwn ith is %k and sum of diff ==0 and seprate k==0 case since  in one ops we can only +k and -k so it is basicall saree +ve diff ko /k krke ans me add krte jao

#include<bits/stdc++.h>
using namespace std;

        long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
            
            if(k==0){
                if(nums1==nums2) return 0;
                return -1;
            }
    
            long long ans=0;
            long long sum=0;
    
            for(int i=0;i<nums1.size();i++){
    
                long long diff = nums1[i]-nums2[i];
    
                if(diff%k!=0) return -1;
    
                if(diff>0) ans += diff/k;
    
                sum += diff;
            }
    
            if(sum!=0) return -1;
    
            return ans;
        }

int main()
{
  vector<int>v = {4,3,1,4};
  vector<int>v2 = {1,3,7,1};
  int k=3;

  long long ans=minOperations(v,v2,k);
  cout<<ans<<endl;


     
}
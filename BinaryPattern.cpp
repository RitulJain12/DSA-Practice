//same question is 410 but in that question we have to use subaaray but here we need to use subset so the only diff is can func 1723
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr, vector<int> &buc, int mid,int k,int idx)
{

    if(idx==arr.size()) return true;
    for(int i=0;i<buc.size();i++)    {
        if(buc[i]+arr[idx]<=mid)
        {
            buc[i]+=arr[idx];
            if(check(arr,buc,mid,k,idx+1)) return true;
            buc[i]-=arr[idx];
        }
    }
    return false;
}
bool ispossible(vector<int> &arr, int mid, int m)
{
   vector<int>buc(m,0);
   return check(arr,buc,mid,m,0);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0, high = accumulate(arr.begin(), arr.end(), 0);
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (ispossible(arr, mid, m))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << endl;
}
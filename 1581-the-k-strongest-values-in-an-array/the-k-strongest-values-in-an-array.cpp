class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {


        vector<int>ans;

        int n=arr.size();
       

        sort(arr.begin(),arr.end());
         int mid=arr[(n-1)/2];

        sort(arr.begin(),arr.end(),[&](int a,int b)
        {
            if(abs(a-mid)==abs(b-mid)) return a>b;

            return abs(a-mid)>abs(b-mid);
        });

    
       vector<int>a(arr.begin(),arr.begin()+k);

         return a;
        
    }
};
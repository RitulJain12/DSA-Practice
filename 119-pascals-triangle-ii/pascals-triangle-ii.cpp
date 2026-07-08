class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return fun(rowIndex+1);
    }
    vector<int> fun(int r)
    {
        vector<int> temp;
        long long ans=1;
        temp.push_back(ans);
        for(int i=1;i<r;i++)
        {
            ans=ans*(r-i);
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }

};
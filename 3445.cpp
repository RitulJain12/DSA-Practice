#include <bits/stdc++.h>
using namespace std;
 
 bool Can(double mid, vector<vector<int>> &squares){
    //ye apka condition ya direction deta he ki agar ye hua toh line uppr ye hua toh line niche
    double left = 0, right = 0;
    for (auto &s : squares) {
        double y = s[1], l = s[2];
        if (y + l <= mid)
            left += l * l;
        else if (y >= mid)
            right += l * l;
        else {
            left += (mid - y) * l;
            right += (y + l - mid) * l;
        }
    }
    return left>=right ;   // agar mid mtlb line uppr he toh niche lao so h=mid wala chalao 
 }
int main() {
    vector<vector<int>> squares={{0,0,2},{1,1,1}};
    double l = 1e18, h = -1e18;
    for (auto &s : squares) {
        l = min(l, (double)s[1]);
        h = max(h, (double)(s[1] + s[2]));
    }
    while (h - l > 1e-6) {
        double mid = (l + h) / 2;
        if (Can(mid, squares))
            h = mid;
        else
            l = mid;
    }
    cout<<h;    
}

// floating point bs me hum diff dekhte he agar h-l<1e-6 se toh wo ans hoga
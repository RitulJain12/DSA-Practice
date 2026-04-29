#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n==0) return false;
    if(n==1) return true;
    if(n%3!=0) return false;
    return isPowerOfTwo(n/3);
}
int main() {
    int n;
    cin >> n;
    cout << isPowerOfTwo(n) << endl;
    return 0;
}
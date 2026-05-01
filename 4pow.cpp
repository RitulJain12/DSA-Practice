#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0) && (__builtin_ctz(n) % 2 == 0);
}
int main() {
    int n;
    cin >> n;
    cout << isPowerOfTwo(n) << endl;
    return 0;
}
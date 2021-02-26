#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;   
long long n, p, q, x, y;  
long long mfind(long long num) {
    if(num <= 0) {
        return 1;    
    }else if (m.find(num) != m.end()) {
        return m[num];
    } else {
        return m[num] = mfind((num/p)-x) + mfind((num/q)-y);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> p >> q >> x >> y;
    m[0] = 1;
    cout << mfind(n);    
    return 0;
}
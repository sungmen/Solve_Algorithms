#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;   
long long n, p, q;  
long long mfind(long long num) {
    if (m.find(num) != m.end()) {
        return m[num];
    } else {
        return m[num] = mfind(num/p) + mfind(num/q);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> p >> q;
    m[0] = 1;
    cout << mfind(n);    
    return 0;
}
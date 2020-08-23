#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        ll a1, a2, a3; // 0 1 2
        cin >> a1 >> a2 >> a3;
        ll b1, b2, b3; // 0 1 2
        cin >> b1 >> b2 >> b3;
        ll c1;
        if(a1 < b3) {
            c1 = a1; // 2 * 2
        } else {
            c1 = b3; // 1 * 2
        }
        a1 -= c1; b3 -= c1;
        c1 = min(a2, b1);
        a2 -= c1; b1 -= c1;
        c1 = min(a3, b2);
        a3 -= c1; b2 -= c1;
        ll res = c1 * 2;
        res -= (min(a2, b3) * 2);
        cout << res << '\n';
    }
}
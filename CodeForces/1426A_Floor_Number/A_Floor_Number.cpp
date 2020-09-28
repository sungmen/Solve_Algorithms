#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin >> t; t--;) {
        int a, b; cin >> a >> b;
        if(a == 1 || a == 2) {
            cout << 1 << '\n';
            continue;
        }
        int fl = 2;
        while(1) {
            int m = (fl-2) * b + 2;
            int n = (fl-1) * b + 2;
            if(m <= a && n >= a) {
                cout << fl << '\n';
                break;
            } else {
                ++fl;
            }
        }
    }
}
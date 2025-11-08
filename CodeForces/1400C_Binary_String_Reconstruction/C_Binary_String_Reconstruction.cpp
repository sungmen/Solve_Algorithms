#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int32_t t;
    for(cin>>t;t--;){
        string s; cin >> s;
        int32_t n = s.size();
        int32_t x; cin >> x;
        int32_t arr[n];
        for (int32_t i = 0; i < n; i++) arr[i] = 1;
        for (int32_t i = 0; i < n; i++) {
            if (s[i] == '0') {
                int32_t c = 0;
                if(i - x >= 0) arr[i - x] = 0;
                if(i + x < n) arr[i + x] = 0;
            }
        }
        char chr[n];
        for (int32_t i = 0; i < n; i++) chr[i] = '0';
        for (int32_t i = 0; i < n; i++) {
            if (i - x >= 0 && arr[i-x] == 1) chr[i] = '1';
            else if (i + x < n && arr[i + x] == 1) chr[i] = '1';
        }
        int32_t l = 0;
        for (int32_t i = 0; i < n; i++) if(s[i] != chr[i]) l=1;
        if (l) cout << -1 << '\n';
        else {
            for (int32_t i = 0; i < n; i++) cout << arr[i];
            cout << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;cin >> n;
    vector<char> v(n);
    int w = 0, r = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 'R') r++;
        if (v[i] == 'W') w++;
    }
    int s = 0;
    for (int i = 0; i < r; i++) if(v[i] == 'W') s++;
    cout << min(r, min(w, s));
}

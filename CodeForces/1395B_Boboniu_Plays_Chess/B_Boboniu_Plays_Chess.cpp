#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int tmpy;
        if (y == m) {
            for ( int ty = m; ty >= 1; ty--) {
                cout << x << " "  << ty << "\n";
            }
            int tmpy = 1;
        }
        else if (y == 1) {
            for (int ty = 1; ty <= m; ty++) {
                cout << x << " " << ty << "\n";
            }
            int tmpy = m;
        } else {
            cout << x << " " << y << "\n";
            for (int i = 1; i <= m; i++) {
                if(i == y) {
                    continue;
                } 
                cout << x << " " << i << "\n";
            }
            tmpy = m;
        }
        vector<bool> vb(n+1, false);
        vb[x] = true;
        for(int i = 1; i <= n; i++) {
            if (!vb[i]) {
                vb[i] = true;
                if(tmpy == m) {
                    for(int ty = m; ty >= 1; ty--) {
                        cout << i << " " << ty << "\n";
                    }
                    tmpy = 1;
                } else {
                    for(int ty = 1; ty <= m; ty++) {
                        cout << i << " " << ty << "\n";
                    }
                    tmpy = m;
                }
            }
        }
}
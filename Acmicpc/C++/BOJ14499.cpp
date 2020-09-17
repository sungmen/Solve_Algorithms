#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, x, y, k;
    cin >> N >> M >> y >> x >> k;
    vector<vector<int>> v(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> c(7, 0);
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        int x_ = 0, y_ = 0;
        switch(t) {
        case 1:
            x_ = 1;
            break;
        case 2:
            x_ = -1;
            break;
        case 3:
            y_ = -1;
            break;
        case 4:
            y_ = 1;
            break;
        }
        if (x+x_ >= 0 && x+x_ < M && y+y_ >=0 && y+y_<N) {
            x += x_;
            y += y_;
            vector<int> tmp(c);
            switch(t) {
            case 1:
                c[1] = tmp[4];
                c[3] = tmp[1];
                c[4] = tmp[6];
                c[6] = tmp[3];
                break;
            case 2:
                c[1] = tmp[3];
                c[3] = tmp[6];
                c[4] = tmp[1];
                c[6] = tmp[4];
                break;
            case 3:
                c[1] = tmp[5];
                c[2] = tmp[1];
                c[5] = tmp[6];
                c[6] = tmp[2];
                break;
            case 4:
                c[1] = tmp[2];
                c[2] = tmp[6];
                c[5] = tmp[1];
                c[6] = tmp[5];
            } // end test case
            if(v[y][x] == 0) {
                v[y][x] = c[6];
            } else {
                c[6] = v[y][x];
                v[y][x] = 0;
            }
            cout << c[1] << '\n';
        } // end if
    } // end for
    return 0;
}
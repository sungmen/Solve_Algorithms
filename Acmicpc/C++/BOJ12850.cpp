#include <bits/stdc++.h>
const int DIV = 1000000007;
using namespace std;
using ll = long long;
using ar = array<array<ll, 8>, 8>;
void mult (ar &l, ar &m, ar &n) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                l[i][j] += m[i][k] * n[k][j];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int d; cin >> d;
/*
    1. 정보과학관
    2. 전산관
    3. 미래관
    4. 신양관
    5. 진리관
    6. 환경직기념관
    7. 학생회관
    8. 형남공학관
*/
    ar arr = {{ 
                {0, 1, 1, 0, 0, 0, 0, 0},
                {1, 0, 1, 1, 0, 0, 0, 0},
                {1, 1, 0, 1, 0, 1, 0, 0},
                {0, 1, 1, 0, 1, 1, 0, 0},
                {0, 0, 0, 1, 0, 1, 1, 0},
                {0, 0, 1, 1, 1, 0, 0, 1},
                {0, 0, 0, 0, 1, 0, 0, 1},
                {0, 0, 0, 0, 0, 1, 1, 0}
            }},
            arr2 = arr;
    vector<ll> v;
    while(d > 1) {
        v.emplace_back(d);
        d = d & 1 ? --d : d / 2;
    }
    for (int t = v.size() - 1; t >= 0; --t) {
        ar res = {{0}};
        v[t] & 1 ? mult(res, arr, arr2) : mult(res, arr2, arr2);
        for (int i = 0; i < 64; ++i) {
                arr2[i/8][i%8] = res[i/8][i%8] % DIV;
        }
    }
    cout << arr2[0][0];
}
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e3;
int n;
long long b;
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> & b) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < n; z++) {
                result[i][j] += a[i][z] * b[z][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> b;
    vector<vector<int>> v(n, vector<int>(n)), ans(n, vector<int>(n, 0)), tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(i==j) ans[i][j] = 1;
        }
    }
    while (b != 1) {
        tmp = v;
        if (b % 2) {
            ans = mul(ans, tmp);
            b -= 1;
        } else {
            v = mul(tmp, tmp);
            b /= 2;
        }
    }
    ans = mul(ans, v);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
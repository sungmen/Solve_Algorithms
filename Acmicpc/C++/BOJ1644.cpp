#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e6 + 1;
bool chk[MAX];
vector<int> prim;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(chk, 1, sizeof(chk));
    int n; cin >> n;
    chk[0] = chk[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (chk[i]) {
            prim.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                chk[j] = 0;
            }
        }
    }
    int cnt = 0, end = 0, sum = 0;
    for (int i = 0; i < prim.size(); ++i) {
        sum += prim[i];
        while (sum > n) {
            sum -= prim[end++];
        }
        if (sum == n) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
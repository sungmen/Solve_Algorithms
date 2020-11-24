#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, H; cin >> N >> H;
    vector<int> b(N/2), u(N/2);
    for (int tc = 0; tc < N; tc++) {
        if(tc%2) cin >> u[tc/2];
        else cin >> b[tc/2];
    }
    sort(b.begin(), b.end());
    sort(u.begin(), u.end());
    int D[H];
    memset(D, 0, sizeof(D));
    int num = 1;
    vector<int>::iterator low;
    for(int i = 1; i <= H; i++) {
        low = lower_bound(b.begin(), b.end(), i);
        int l = (low - b.begin());
        D[i - 1] += N/2 - l;
        low = lower_bound(u.begin(), u.end(), i);
        l = (low - u.begin());
        D[H - i] += N/2 - l;
    }
    int* min_v;
    min_v = min_element(D, D + H);
    int cnt = 0;
    for (int i = 0; i < H; i++) if (*min_v == D[i]) cnt++;
    cout << *min_v << ' ' << cnt;
    return 0;
}
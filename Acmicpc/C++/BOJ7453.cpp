#include<bits/stdc++.h>
using namespace std;
int a[4001], b[4001], c[4001], d[4001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> ab, cd;
    int cntZero = 0, cntZero2 = 0;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ab.emplace_back(a[i] + b[j]);
            cd.emplace_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    long long cnt = 0;
    vector<int>::iterator low, up;
    for (int i = 0; i < n*n; i++) {
        long long tmp = ab[i];
        up = upper_bound(cd.begin(), cd.end(), -tmp);
        low = lower_bound(cd.begin(), cd.end(), -tmp);
        int u = up - cd.begin();
        int l = low - cd.begin();
        if (u == l) continue;
        cnt += u - l;
    }
    cout << cnt;
    return 0;
}
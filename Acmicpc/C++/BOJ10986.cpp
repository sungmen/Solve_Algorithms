#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e6+1
long long arr[MAX];
long long num[MAX];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; 
    cin >> n >> m;
    num[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] = (arr[i-1] + arr[i]) % m;
        num[arr[i]]++;
    }
    long long ans = 0;
    while (m--) {
        ans += (num[m] * (num[m]-1) / 2);
    }
    cout << ans;
    return 0;
}

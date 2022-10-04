#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    long long k; cin >> k;
    long long sum = 0;
    unordered_map<long long, int> um;
    um[sum]++;
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        long long a; cin >> a;
        sum += a;
        cnt += um[sum - (k * i)];
        um[sum - (k * i)]++;
    }
    cout << cnt;
    return 0;
}

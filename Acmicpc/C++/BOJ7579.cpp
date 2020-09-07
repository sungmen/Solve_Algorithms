#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M; 
    cin >> N >> M;
    vector<int> a(N);
    for(int i = 0; i < N; cin >> a[i], i++);
    vector<int> m(N);
    int sum = 0;
    for(int i = 0; i < N; cin >> m[i], sum += m[i], i++);
    vector<int> dp(sum+1);
    for (int i = 0; i < N; i++)
        for (int j = sum; j >= m[i]; dp[j] = max(dp[j], dp[j-m[i]] + a[i]), j--);
    int i = 0; 
    for(i=0; i < sum, dp[i] < M; i++);
    cout << i;
}
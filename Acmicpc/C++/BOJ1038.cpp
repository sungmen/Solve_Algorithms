#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
void dfs(long long num, int cur) {
    v.emplace_back(num);
    long long tmp = num * 10;
    for (int i = 0; i < cur; i++)  {
        long long next = tmp + i;
        dfs(next, i);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    v.emplace_back(0);
    for (int i = 1; i <= 9; i++) dfs(i, i);
    sort(v.begin(), v.end());
    if(n >= v.size()) cout << -1;
    else cout << v[n];
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}
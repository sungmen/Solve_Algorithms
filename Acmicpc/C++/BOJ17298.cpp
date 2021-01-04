#include <bits/stdc++.h>
using namespace std;
int main () {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int arr[n], res[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    stack<int> stk;
    stk.push(arr[n-1]);
    res[n-1] = -1;
    for (int i = n - 2; i >= 0; i--) {
        while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
        if (!stk.empty()) res[i] = stk.top();
        else res[i] = -1;
        stk.push(arr[i]);
    }
    for (auto i : res) cout << i << ' ';
    return 0;
}
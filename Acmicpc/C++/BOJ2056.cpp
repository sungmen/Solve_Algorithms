#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n; cin>>n;
    vector<int> dp(n+1, 0);
    vector<int> arr(n+1, 0);
    for(int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        arr[i] = t;
        if(i == 1) dp[i] = arr[i];
        else {
            int max_v = 0;
            for (int j = 0; j < p; j++) {
                int k;
                cin >> k;
                max_v = max(dp[k], max_v);
            }
            dp[i] = max_v + arr[i];
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
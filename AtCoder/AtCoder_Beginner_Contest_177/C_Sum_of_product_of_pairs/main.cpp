#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1000000007;
ll findProductSum(int A[], int n) { 
    vector<long long> dp(n);
    for (int i = n-2; i >= 0; i--) dp[i] = (dp[i+1] + A[i+1]) % mod; 
    ll ans = 0; 
    for (int i = 0; i < n - 1; i++) {ans += ((A[i] * dp[i]) %mod);}
    return ans; 
} 
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n; cin>>n;
    int arr[200001];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << findProductSum(arr, n) % mod;
}

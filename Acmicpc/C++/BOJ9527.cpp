#include <bits/stdc++.h>
using namespace std;
#define fest ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ll long long

// reference : https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/?ref=rp
ll countingOnes(ll N){ 
    ll t = 2, ans = 0; 
    ll n = N; 
    while(n){ 
        ans += (N/t) * (t>>1); 
        if((N&(t-1)) > (t>>1)-1) ans += (N&(t-1)) - (t>>1)+1; 
        t <<= 1; 
        n >>= 1; 
    } 
    return ans; 
} 

int main() {
    fest
    ll A, B; 
    scanf("%lld%lld", &A, &B);
    cout << countingOnes(B) - countingOnes(A - 1);
}
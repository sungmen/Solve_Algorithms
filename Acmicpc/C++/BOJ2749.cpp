#include <stdio.h>
#define ll long long

int max = 1500000;
ll dp[1500001] = {0, 1, 1, 2};
int INF = 1000000;

int main() {
    ll n;
    scanf("%lld", &n);

    for(int i = 4; i <= max; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % INF;
    }

    printf("%lld", dp[n % max] );


    return 0;
}
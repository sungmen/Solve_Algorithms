#include <stdio.h>
#define ll long long
ll arr[1000001] = {0, 1, 2, 3, 5,};
int mod = 15746;
int main() {
    int n;
    scanf("%d", &n);    
    for(int i = 5; i <= 1000000; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % mod;
    }
    printf("%lld", arr[n]);

    return 0;
}
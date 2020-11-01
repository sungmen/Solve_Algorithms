#include <iostream>
#include <string.h>
int main() {
    // freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    long long res = 0;
    while(n--) {
        long long a, b; scanf("%lld%lld", &a, &b);
        res += ((b-a+1) * (a+b))/2;
    }
    printf("%lld", res);
}
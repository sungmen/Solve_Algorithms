#include <stdio.h>
#define ll long long
ll mod = 1000000000;
ll arr[101][11];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < 10;i ++) arr[0][i] = 1;
    for(int i = 1; i < n; i++) 
        for (int j = 0; j < 10; j++) 
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]);
    ll sum = 0;
    for(auto j : arr[n-1])
        sum += j;
    printf("%lld", sum % mod);
}
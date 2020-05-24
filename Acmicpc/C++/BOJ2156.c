#include <stdio.h>

int arr[10001] = {0, };
int dp[10001] = {0,};
int max(int a, int b) {return a>b?a:b;}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i < n + 3; i++)
        scanf("%d", &arr[i]);

    int MAX = 0;
    for(int i = 3; i < n + 3; i++) {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);
        dp[i] = max(dp[i-1], dp[i]);
        MAX = max(MAX, dp[i]);
    }

    printf("%d", MAX);
    return 0;
}
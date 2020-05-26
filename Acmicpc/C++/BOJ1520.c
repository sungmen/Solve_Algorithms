#include <stdio.h>
#include <memory.h>
int arr[501][501];
int dp[501][501] = {-1};
int x, y;
int dfs(int n, int m) {
    if(dp[n][m] != -1) return dp[n][m];
    if(n < 0 || m < 0 || n >= x || m >= y) return 0;
    if(n == 0 && m == 0) return 1;
    dp[n][m] = 0;
    if(arr[n][m] < arr[n+1][m])
        dp[n][m] += dfs(n+1, m);
    if(arr[n][m] < arr[n][m+1])
        dp[n][m] += dfs(n, m+1);
    if(arr[n][m] < arr[n][m-1])
        dp[n][m] += dfs(n, m-1);
    if(arr[n][m] < arr[n-1][m])
        dp[n][m] += dfs(n-1, m);
    return dp[n][m];
}

int main() {

    scanf("%d%d", &x, &y);
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    printf("%d", dfs(x-1, y-1));


    return 0;
}
#include <stdio.h>
#include <algorithm>

int arr[101][2], dp[100001];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for(int t = 0; t < n; t++)
        scanf("%d%d", &arr[t][0], &arr[t][1]);

    for(int i = 0; i < n; i++)
        for(int j = k; j >= arr[i][0]; j--)
            dp[j] = std::max(dp[j], dp[j - arr[i][0]] + arr[i][1]);

    printf("%d", dp[k]);

    return 0;
}
#include <stdio.h>

int arr[2][100000];
int dp[2][100000];

int main() 
{
    int t = 0;
    scanf("%d", &t);
    for (int test_c = 0; test_c < t; test_c++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];

        for (int i = 2; i < n; i++)
        {
            dp[0][i] = arr[0][i] + (dp[1][i-2] > dp[1][i-1] ? dp[1][i-2] : dp[1][i-1]);
            dp[1][i] = arr[1][i] + (dp[0][i-2] > dp[0][i-1] ? dp[0][i-2] : dp[0][i-1]);
        }

        printf("%d\n", dp[0][n-1] > dp[1][n-1] ? dp[0][n-1] : dp[1][n-1]);
    }
}
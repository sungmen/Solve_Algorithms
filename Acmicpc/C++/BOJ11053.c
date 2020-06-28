#include <stdio.h>
int main() {
    int A;
    scanf("%d", &A);
    
    int arr[1001] = {0};
    for(int i = 0; i <A; i++) {
        scanf("%d", &arr[i]);
    }

    int dp[1001];
    for(int i = 0 ; i < A; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    
    int maxLength = dp[0];
    for(int i = 1; i < A; i++) {
        if (maxLength < dp[i])
            maxLength = dp[i];
    }    

    printf("%d", maxLength);

    return 0;
}
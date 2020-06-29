#include <stdio.h>

int arr[501][501];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    n -= 2;
    while(n >= 0) {
        for (int i = 0; i <= n; i++) {
            arr[n][i] += max(arr[n+1][i], arr[n+1][i+1]);
        }
        --n;
    }

    printf("%d", arr[0][0]);

    return 0;
}
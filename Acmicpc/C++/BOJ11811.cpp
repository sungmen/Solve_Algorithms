#include <stdio.h>

int main() {
    int arr[1001] = {0};
    int n, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            arr[i] = arr[i] | num;
        }
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
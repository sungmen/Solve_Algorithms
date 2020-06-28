#include <stdio.h>
int arr[300][300];

void setArray(int n, int m);
void setPosition(int i, int j, int x, int y);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    setArray(n, m);
    int k;
    scanf("%d", &k);
    int i, j, x, y;
    for(int l = 0; l < k; l++) {
        scanf("%d%d%d%d", &i, &j, &x, &y);
        setPosition(i, j, x, y);
    }

}

void setArray(int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]); 
}

void setPosition(int i, int j, int x, int y) {
    int sum = 0;
    for(int i2 = i; i2 <= x; i2++) {
        for (int j2 = j; j2 <= y; j2++) {
            sum += arr[i2-1][j2-1];
        }
    }
    printf("%d\n", sum);
}
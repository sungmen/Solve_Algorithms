#include <stdio.h>
int main() {
    int t; scanf("%d", &t);
    for (int tc = 0; tc < t; tc++) {
        int n, m, a, b; scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) scanf("%d%d", &a, &b);
        printf("%d\n", n-1);
    }
}
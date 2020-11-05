#include <stdio.h>
#include <string.h>
int main() {
    // freopen("input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        int d[10001];
        memset(d, 0, sizeof(d));
        int n; scanf("%d", &n);
        int sum = 0;
        d[0] = 1;
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            sum += num;
            for (int j = sum; j >= 0; --j) {
                if (d[j]) {
                    d[j + num] = 1;
                }
            }
            d[num] = 1;
        }
        int cnt = 0;
        for(int i = 0; i <= 10000; i++) if(d[i]) cnt++;
        printf("#%d %d\n", tc, cnt);
    }
}
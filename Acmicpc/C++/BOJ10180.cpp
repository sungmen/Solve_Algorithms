#include <stdio.h>


int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int cnt = 0;
        while(n--) {
            int v, f, c;
            scanf("%d%d%d", &v, &f, &c);
            if((double)d/(double)v <= (double)f/(double)c)
                cnt++;

        }
        printf("%d\n", cnt);
    }

    return 0;
}
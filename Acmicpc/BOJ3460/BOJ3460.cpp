#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        int pos = 0;
        while(n != 0) {
            int cn = n % 2;
            if(cn == 1)
                printf("%d ", pos);
            n /= 2;
            pos++;
        }
        printf("\n");

    }

    return 0;
}
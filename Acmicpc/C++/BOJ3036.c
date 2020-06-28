#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n, f;
    scanf("%d%d", &n, &f);
    n--;
    while(n--) {
        int s;
        scanf("%d", &s);
        int gc = gcd(f, s);
        printf("%d/%d\n", f / gc, s / gc);
    }

    return 0;
}
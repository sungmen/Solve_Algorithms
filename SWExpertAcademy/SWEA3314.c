#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            int n;
            scanf("%d", &n);
            if (n <40)
                sum += 40;
            else
                sum += n;
        }
        printf("#%d %d\n", test_case, sum / 5);
    }
}
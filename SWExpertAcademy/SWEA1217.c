#include <stdio.h>

int recur(int n, int m) {
        if (m == 1) {
                return n;
        } else {
                return n * recur(n, m-1);
        }
}

int main() {
        for(int test_case = 1; test_case <= 10; test_case++) {
                int n;
                scanf("%d", &n);

                int num, pow_;
                scanf("%d%d", &num, &pow_);

                printf("#%d %d\n", test_case, recur(num, pow_));
        }
        return 0;
}

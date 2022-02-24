#include <iostream>
using namespace std;
#define MAX (int)1e9
int main() {
    int m;
    scanf("%d", &m);
    int sum = 0;
    for (int i = 1; i <= MAX; i++) {
        int t = i;
        while (!(t % 5)) {
            sum++;
            t /= 5;
        }
        if (++sum == m) {
            printf("%d", 5 * i);
            return 0;
        } else if (sum > m) {
            printf("-1");
            return 0;
        }
    }
    return 0;
}

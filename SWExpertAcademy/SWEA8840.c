#include <stdio.h>
#define ll long

int main() {
 	int test_case;
   scanf("%d", &test_case);
    for(int t = 1; t <=test_case; t++) {
        ll L;
        scanf("%lld", &L);
     	printf("#%lld %lld\n", t, ((L-1)/2) * ((L-1)/2));
    }
}
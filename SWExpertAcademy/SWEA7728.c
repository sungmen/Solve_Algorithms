#include <stdio.h>
int main() {
    int t;
    scanf("%d",&t);
    for(int test_case=1; test_case <= t; test_case++) {
    	int n[10] ={0};
        int cnt = 0;
    	int number;
        scanf("%d", &number);
        int c;
        while(number != 0) {
         	c = number % 10;
            n[c]++;
            number /= 10;
        }
        for(int i = 0; i < 10; i++)
            if(n[i] > 0)
                cnt++;
        printf("#%d %d\n", test_case, cnt);
    }
    return 0;
}

#include <stdio.h>
int main(void)
{
    int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
		printf("#%d %d %d\n", test_case, a < b ? a : b,  a+b-n <= 0? 0 : a+b-n);
	}
	return 0;
}
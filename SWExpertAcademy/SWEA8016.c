#include <stdio.h>
#define ll long long

int main()
{
    int T;
    scanf("%d", &T);
    for(int test_c = 1; test_c <= T; test_c++)
    {
        ll l_value = 1;
        ll r_value = 1;
        long long n;
        scanf("%lld", &n);

        if (n > 1) 
        {
            r_value = 2 * (n * n) - 1;
            n = n - 1;
            l_value = 2 * (n * n) + 1;
        }
        printf("#%d %lld %lld\n", test_c, l_value, r_value);
    }
    return 0;
}
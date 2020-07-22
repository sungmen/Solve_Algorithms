#include <stdio.h>
#include <limits.h>
#define ll long long
int min_n = INT_MAX;
void rep(ll c, int idx, ll des)
{
    if (c > des)
    {
        return;
    }
    ll tmp = c;
    c *= 2;
    if (c == des)
    {
        min_n = min_n > idx ? idx : min_n;
    }
    rep(c, idx + 1, des);
    tmp = tmp * 10 + 1;
    if (tmp == des)
    {
        min_n = min_n > idx ? idx : min_n;
    }
    rep(tmp, idx + 1, des);
}

int main()
{
    ll A, B;
    scanf("%lld%lld", &A, &B);
    rep(A, 1, B);
    if (min_n == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", min_n + 1);
    }
}
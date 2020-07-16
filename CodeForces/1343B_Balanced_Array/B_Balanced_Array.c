#include <stdio.h>
typedef long long ll;

int main () 
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        int chk = 0;
        if (n % 4 == 0)
        {
            chk = 1;
        }
        ll firstHalf = 0;
        ll secondHalf = 0;
        switch(chk)
        {
            case 0:
                printf("NO\n");
                break;
            case 1:
                
                printf("YES\n");
                for(ll i = 2; i <= n; i+=2)
                {
                    printf("%lld ", i);
                    firstHalf += i;
                }
                for (ll i = 1; i < n - 1; i+=2)
                {
                    printf("%lld ", i);
                    secondHalf += i;
                }
                printf("%lld\n", firstHalf - secondHalf);

                break;
        }

        
    }

    return 0;
}
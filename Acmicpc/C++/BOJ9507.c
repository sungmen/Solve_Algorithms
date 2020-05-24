#include <stdio.h>
#define ll long long
ll pibo[70] = {1,1,2,4,};
int main() {
    for(int i = 4; i <= 69; i++)
        pibo[i] = pibo[i-1] + pibo[i-2] + pibo[i-3] + pibo[i-4];
    
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int i;
        scanf("%d", &i);
        printf("%lld\n", pibo[i]);
    }

    return 0;
}
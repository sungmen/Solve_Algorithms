#include <stdio.h>
#define ll long long
ll remain;

ll power(ll num, ll powerNum) {
    switch(powerNum){
        case 0:
            return 1;
        case 1:
            return num;
        default:
            if(powerNum % 2)
                return power(num, powerNum - 1) * num;
            else {
                ll half = power(num, powerNum / 2) % remain;
                return half * half % remain;
            }
    }
}

int main() {
    ll num, powerNum;
    scanf("%lld%lld%lld", &num, &powerNum, &remain);
    printf("%lld", power(num, powerNum) % remain);
}
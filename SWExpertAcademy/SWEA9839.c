#include <stdio.h> 
#define ll long long
int arr[1001] = {0};

int chk (ll n) {
    ll tmp = n;
    int s = tmp % 10;
    tmp /= 10;
    
    while(tmp != 0) {
        int f = tmp % 10;
        tmp /= 10;
        if (s != f+1)
            return 0;
        s = f;
    }
    return 1;
}

int main() {
    int test;
    scanf("%d", &test);
    for (int test_case = 1; test_case <= test; test_case++) {
        int N;
        scanf("%d", &N);
        if (N == 1) {
            printf("%d", -1);
            break;
        }
            
        for(int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int max = -1;
        for(int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int mul = arr[i] * arr[j];
                if(chk(mul))
                    max = max < mul ? mul : max;
            }
        }

        printf("#%d %d\n", test_case, max);

    }

    return 0;
}
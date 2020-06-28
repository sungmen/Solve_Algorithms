#include <cstdio>

int stk[10001];
char command[6];

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    while(N--) {
        scanf("%s", command);
        switch(command[0]){
        case 'p':
            command[1] == 'u' ? scanf("%d", &stk[cnt++]):printf("%d\n", cnt?stk[--cnt]:-1);
            break;
        case 's':
            printf("%d\n", cnt);
            break;
        case 'e':
            printf("%d\n", cnt?0:1);
            break;
        case 't':
            printf("%d\n", cnt?stk[cnt-1]:-1);
            break;
        }
    }

    return 0;
}

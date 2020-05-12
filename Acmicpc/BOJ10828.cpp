#include <iostream>

using namespace std;

int stk[10001];

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    while(N--) {
        string com;
        cin >> com;
        if(com == "push") {
            int X; 
            cin >> X;
            stk[cnt++] = X;
        } else if (com == "pop") {
            printf("%d\n", cnt?stk[--cnt]:-1);
        } else if (com == "size") {
            printf("%d\n", cnt);
        } else if (com == "empty") {
            printf("%d\n", cnt?0:1);
        } else if (com == "top") {
            printf("%d\n", cnt?stk[cnt-1]:-1);
        }
    }

    return 0;
}
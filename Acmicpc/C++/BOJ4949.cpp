#include <iostream>
char stk[101];
using namespace std;

int main() {
    while(1) {
        int idx = 0;
        string carr;
        getline(cin, carr);
        if(carr[0] == '.'){
            break;
        }
        int flag = 0;
        for(int i = 0; i < 101; i++) {
            if(carr[i] == '.') {
                break;
            }
            if(carr[i] == '[')
                stk[idx++] = '[';
            if (carr[i] == '(')
                stk[idx++] = '(';
            if (carr[i] == ']') {
                if(idx && stk[idx-1] == '[')
                    --idx;
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
            if (carr[i] == ')') {
                if(idx && stk[idx-1] == '(')
                    --idx;
                else {
                    printf("no\n");
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) continue;
        idx ? printf("no\n") : printf("yes\n");
    }

    return 0;
}
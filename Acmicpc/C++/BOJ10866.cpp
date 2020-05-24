#include <stdio.h>
#include <deque>
std::deque<int> dq;
char ch[10] = {0,};

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", &ch);
        if(ch[0] == 'p') {
            if (ch[1] == 'u') {
                if (ch[5] == 'f') {
                    int x;scanf("%d", &x);
                    dq.push_front(x);
                } else {
                    int x;scanf("%d", &x);
                    dq.push_back(x);
                }
            } else {
                if (ch[4] == 'f') {
                    printf("%d\n", dq.empty()?-1:dq.front());
                    if(!dq.empty()) dq.pop_front();
                } else {
                    printf("%d\n", dq.empty()?-1:dq.back());
                    if(!dq.empty()) dq.pop_back();
                }
            }
        } else if (ch[0] == 's') {
            printf("%d\n", dq.empty()?0:dq.size());
        } else if (ch[0] == 'e') {
            printf("%d\n", dq.empty()?1 : 0);
        } else if (ch[0] == 'f') {
            printf("%d\n", dq.empty()?-1:dq.front());
        } else if (ch[0] == 'b') {
            printf("%d\n", dq.empty()?-1:dq.back());
        }
    }
    return 0;
}
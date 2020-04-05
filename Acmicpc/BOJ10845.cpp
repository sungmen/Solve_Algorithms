#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t_case;
    scanf("%d", &t_case);
    queue<int> q;
    while(t_case--) {
        string command;
        cin >> command;
        int n;
        switch(command[1]) {
        case 'u':
            cin >> n;
            q.push(n);
            break;
        case 'o':
            if(!q.empty()) {
                printf("%d\n", q.front());
                q.pop();
            } else {
                puts("-1");
            }
            break;
        case 'i':
            printf("%d\n", q.size());
            break;
        case 'm':
            printf("%d\n", q.empty()?1:0);
            break;
        case 'r':
            if(!q.empty()) {
                printf("%d\n", q.front());
            } else {
                puts("-1");
            }
            break;
        case 'a':
            if(!q.empty()) {
                printf("%d\n", q.back());
            } else {
                puts("-1");
            }
            break;
        }
    }

    return 0;
}

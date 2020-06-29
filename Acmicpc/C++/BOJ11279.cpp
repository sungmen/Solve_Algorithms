#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    priority_queue<int, vector<int>, less<int> > pq;
    while(t--) {
        int num;
        scanf("%d", &num);
        switch(num) {
        case 0:
            if(pq.empty())
                puts("0");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
            break;
        default:
            pq.push(num);
            break;
        }
    }
    return 0;
}

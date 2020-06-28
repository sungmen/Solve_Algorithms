#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    for(int i = 1; i <= n; i++)
        q.push(i);

    while(q.size()!=1) {
        if(!q.empty())
            q.pop();
        q.push(q.front());
        q.pop();
    }

    printf("%d", q.front());
    return 0;
}
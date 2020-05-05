#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

    while(n--) {
        int t;
        scanf("%d", &t);

        if(maxq.size()!=minq.size()) minq.push(t);
        else maxq.push(t);
         
        if(!minq.empty() && !maxq.empty() && minq.top() < maxq.top()) {
            int temp = maxq.top();
            maxq.pop(); maxq.push(minq.top());
            minq.pop(); minq.push(temp);
        }
        printf("%d\n", maxq.top());
    }

    return 0;
}
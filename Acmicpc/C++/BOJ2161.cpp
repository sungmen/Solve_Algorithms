#include <stdio.h>
#include <deque>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	deque <int> dq;
	for(int i = 1; i <= n; i++)
		dq.push_back(i);
	while(!dq.empty()) {
		printf("%d ", dq.front());
		dq.pop_front();
		if(!dq.empty()){
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	return 0;
}

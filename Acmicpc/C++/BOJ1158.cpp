#include <cstdio>
#include <deque>

using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	deque<int> dq;
	for(int i = 0; i < n; i++) {
		dq.push_back(i+1);
	}
	printf("<");
	while(dq.size()!=1){
		for(int i = 0; i < k - 1; i++){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		printf("%d, ", dq.front());
		dq.pop_front();
	}
	printf("%d>\n", dq[0]);


	return 0;
}

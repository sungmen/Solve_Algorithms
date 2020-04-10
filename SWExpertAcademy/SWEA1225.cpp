#include <iostream>
#include <queue>
using namespace std;
int main() {
	int di[5] = {1,2,3,4,5};
    for(int t = 1; t <= 10; t++) {
        int number;
        scanf("%d", &number);
		queue<int> v;
        for (int i = 0; i < 8; i++){
            int inp;
            cin >> inp;
            v.push(inp);
        }
        int n = 0;
        while(v.back() > 0) {
            v.push(v.front()-di[n++]);
            v.pop(); 
            if(n==5)
                n = 0;
        }
        printf("#%d ", t);
		while(v.size() != 1){
            cout << v.front() << " ";
            v.pop();
        }
        printf("0\n");
    }

    return 0;
}
#include <iostream>
using namespace std;

int u[44];
int r[1001];

int main() {
    fill_n(r, 1001,0);
    for(int i = 1; i <=44; i++) {
        u[i-1] = (i*(i+1))/2;
    }
    for(int i = 0; i < 44; i++) {
        for(int j = 0; j < 44; j++) {
            for(int z = 0; z < 44; z++) {
                if(u[i]+u[j]+u[z] < 1001 && r[u[i]+u[j]+u[z]] == 0)
                    r[u[i]+u[j]+u[z]] = 1;
            }
        }
    }

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int res;
        scanf("%d", &res);
        cout << r[res] << "\n";
        
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    vector<int> vcnt(n, 0);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    int longMin = 0;
    for(int i = n - 1; i >= 0; --i) {
        int cnt = 0;
        for(int j = i; j < n; j++) {
            if (cnt <= vcnt[j] && v[i] > v[j]) {
                cnt = vcnt[j];
            }
        }
        vcnt[i] = ++ cnt;
        longMin = max(cnt, longMin);
    }

    printf("%d", longMin);

    return 0;
}
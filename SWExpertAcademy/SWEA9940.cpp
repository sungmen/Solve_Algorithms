#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int test_case;
    scanf("%d", &test_case);
    for(int x = 1; x <= test_case; x++) {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        sort(v.begin(), v.end());
        int chk = 1;
        for(int i= 0; i < n; i++) {
            if(v[i] != i + 1) {
                chk = 0;
                break;
            }
        }
        printf("#%d %s\n", x, chk ? "Yes" : "No");
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> v(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    std::sort(v.begin(), v.end());

    for(int i = n; i >= int(n/2); i--) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if (v[j] >= i)
                ++cnt;
        }
        if(cnt >= i && n - cnt <= i){
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", v[0]);

    return 0;
}
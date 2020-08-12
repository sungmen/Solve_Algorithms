#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin>>t;t--;){
        long long r, g, b, w;
        cin >> r >> g >> b >> w;
        int cnt = 0;
        if(r % 2) {
            cnt++;
        }
        if (b % 2) {
            cnt ++;
        }
        if (g % 2) {
            cnt ++;
        }
        if (w % 2) {
            cnt ++;
        }
        if (cnt > 1) {
            if(r != 0 && g != 0 && b != 0) {
                r -= 1;
                g -= 1;
                b -= 1;
                w += 3;
                cnt = 0;
                if(r % 2) {
                    cnt++;
                }
                if (b % 2) {
                    cnt ++;
                }
                if (g % 2) {
                    cnt ++;
                }
                if (w % 2) {
                    cnt ++;
                }
                if (cnt > 1) {
                    printf("No\n");
                } else {
                    printf("Yes\n");
                }
            } else {
                printf("No\n");
            }
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
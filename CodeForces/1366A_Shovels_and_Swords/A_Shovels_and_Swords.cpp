#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int a, b;
        cin >> a >> b;

        if (a < 1 || b < 1) {
            cout << 0 << "\n";
            continue;
        }
        int cnt=0;
        while (a > 1000000 && b > 1000000) {
            if (a > b && b >= 100000 && a >= 200000) {
                a -= 200000;
                b -= 100000;
                cnt+=100000;
            } else if (a < b && a >= 100000 && b >= 200000) {
                a -= 100000;
                b -= 200000;
                cnt+=100000;
            } else if (a == b && a >= 200000 && b >= 100000) {
                a-=200000;
                b-=100000;
                cnt+=100000;
            } else {
                break;
            }
        }
        while (a > 100000 && b > 100000) {
            if (a > b && b >= 10000 && a >= 20000) {
                a -= 20000;
                b -= 10000;
                cnt+=10000;
            } else if (a < b && a >= 10000 && b >= 20000) {
                a -= 10000;
                b -= 20000;
                cnt+=10000;
            } else if (a == b && a >= 20000 && b >= 10000) {
                a-=20000;
                b-=10000;
                cnt+=10000;
            } else {
                break;
            }
        }
        while (a > 10000 && b > 10000) {
            if (a > b && b >= 1000 && a >= 2000) {
                a -= 2000;
                b -= 1000;
                cnt+=1000;
            } else if (a < b && a >= 1000 && b >= 2000) {
                a -= 1000;
                b -= 2000;
                cnt+=1000;
            } else if (a == b && a >= 2000 && b >= 1000) {
                a-=2000;
                b-=1000;
                cnt+=1000;
            } else {
                break;
            }
        }
        while (a > 1000 && b > 1000) {
            if (a > b && b >= 100 && a >= 200) {
                a -= 200;
                b -= 100;
                cnt+=100;
            } else if (a < b && a >= 100 && b >= 200) {
                a -= 100;
                b -= 200;
                cnt+=100;
            } else if (a == b && a >= 200 && b >= 100) {
                a-=200;
                b-=100;
                cnt+=100;
            } else {
                break;
            }
        }
        while (a > 100 && b > 100) {
            if (a > b && b >= 10 && a >= 20) {
                a -= 20;
                b -= 10;
                cnt+=10;
            } else if (a < b && a >= 10 && b >= 20) {
                a -= 10;
                b -= 20;
                cnt+=10;
            } else if (a == b && a >= 20 && b >= 10) {
                a-=20;
                b-=10;
                cnt+=10;
            } else {
                break;
            }
        }
        while (a > 0 && b > 0) {
            if (a > b && b >= 1) {
                a -= 2;
                b -= 1;
                cnt ++;
            } else if (a < b && a >= 1) {
                a -= 1;
                b -= 2;
                cnt ++;
            } else if (a == b && a >= 2 && b >= 1) {
                a-=2;
                b-=1;
                cnt++;
            } else {
                break;
            }
        }
        cout << cnt << "\n";      


    }

    return 0;
}
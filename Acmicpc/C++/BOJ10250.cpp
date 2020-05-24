// https://www.acmicpc.net/problem/10250

#include<iostream>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    while(test_case--) {
        int H, W, N;
        cin >> H >> W >> N;
        int c = N / H, fl = N % H;
        if (!fl){
            cout << (H*100) + (c) << endl;
        } else {
            cout << (fl * 100) + (c + 1) << endl;
        }

    }

    return 0;
}

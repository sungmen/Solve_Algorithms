#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    vector<string> arr(51, "-1");
    int j = 1;
    for(int i = 1; i <= 9; i++) {
        arr[j++] = i + '0';
    }
    for(int i = 1; i <= 8; i++) {
        arr[j] = (i +'0');
        arr[j] += '9';
        j++;
    }
    for(int i = 1; i <= 7; i++) {
        arr[j] = (i +'0');
        arr[j] += "89";
        j++;
    }
    for(int i = 1; i <= 6; i++) {
        arr[j] = (i +'0');
        arr[j] += "789";
        j++;
    }
    for(int i = 1; i <= 5; i++) {
        arr[j] = (i +'0');
        arr[j] += "6789";
        j++;
    }
    for(int i = 1; i <= 4; i++) {
        arr[j] = (i +'0');
        arr[j] += "56789";
        j++;
    }
    for(int i = 1; i <= 3; i++) {
        arr[j] = (i +'0');
        arr[j] += "456789";
        j++;
    }
    for(int i = 1; i <= 2; i++) {
        arr[j] = (i +'0');
        arr[j] += "3456789";
        j++;
    }
    for(int i = 1; i <= 1; i++) {
        arr[j] = (i +'0');
        arr[j] += "23456789";
        j++;
    }
// arr[1]= 1;
// arr[2]= 2;
// arr[3]= 3;
// arr[4]= 4;
// arr[5]= 5;
// 6 6
// 7 7
// 8 8
// 9 9
// 10 19
// 11 29
// 12 39
// 13 49
// 14 59
// 15 69
// 16 79
// 17 89
// 18 189
// 19 289
// 20 389
// 21 489
// 22 589
// 23 689
// 24 789
// 25 1789
// 26 2789
// 27 3789
// 28 4789
// 29 5789
// 30 6789
// 31 16789
// 32 26789
// 33 36789
// 34 46789
// 35 56789
// 36 156789
// 37 256789
// 38 356789
// 39 456789
// 40 1456789
// 41 2456789
// 42 3456789
// 43 13456789
// 44 23456789
// 45 123456789
// 46 -1
// 47 -1
// 48 -1
// 49 -1
// 50 -1

    for (cin >> t ; t--; ) {
        int x; cin >> x;
        cout << arr[x] << '\n';
    }
    return 0;
}
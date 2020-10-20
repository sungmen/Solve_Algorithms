#include <bits/stdc++.h>
using namespace std;
int solution(int n) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int answer = 0;
    int arr[18];
    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i <= 17; i++) arr[i] = arr[i-1]*3;
    string str;
    int board = 0;
    for (int i = 0; i <= 17; i++) {
        if(n < arr[i]) {
            board = i - 1;
            break;
        }
    }
    while(board >= 0) {
        str += ((n / arr[board])+'0');
        n = (n%arr[board]);
        board--;
    }
    reverse(str.begin(), str.end());
    for (int i = str.length()-1; i >= 0; i--) {
        answer += ((str[i]-'0') * arr[str.length()-1-i]);
    }
    return answer;
}
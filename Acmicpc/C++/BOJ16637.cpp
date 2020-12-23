#include <bits/stdc++.h>
using namespace std;
long long res;
int n;
void dfs (long long  *arr, long long  *arr2, char* op, int i, long long  sum);
void dfs2 (long long  *arr, long long  *arr2, char* op, int i, long long  sum);
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str;
    cin >> n >> str;
    res = LLONG_MIN;
    long long arr[(n+1)/2], arr2[n/2];
    char op[(n+1)/2];
    for (int i = 0; i < str.size(); i++) {
        if (!(i % 2)) arr[i / 2] = str[i] - '0';
        else op[i/2] = str[i];
    }
    for (int i = 0; i < n/2; i++) {
        if (op[i] == '+') arr2[i] = arr[i] + arr[i+1];
        else if (op[i] == '-') arr2[i] = arr[i] - arr[i+1];
        else if (op[i] == '*') arr2[i] = arr[i] * arr[i+1];
    }
    dfs(arr, arr2, op, 0, arr[0]);
    cout << res;
    return 0;
}
void dfs (long long  *arr, long long  *arr2, char* op, int i, long long  sum) {
    if (i > n/2) return;
    if (i == n/2) {
        if (res < sum) {
            res = sum;
        }
        return;
    }
    long long sum1 = sum;
    long long sum2 = sum;
    if (op[i] == '+') {
        sum1 += arr[i+1];
        sum2 += arr2[i+1];
    } else if (op[i] == '-') {
        sum1 -= arr[i+1];
        sum2 -= arr2[i+1];
    } else if (op[i] == '*') {
        sum1 *= arr[i+1];
        sum2 *= arr2[i+1];
    }
    dfs(arr, arr2, op, i+1, sum1);
    dfs2(arr, arr2, op, i+1, sum2);
}
void dfs2 (long long  *arr, long long  *arr2, char* op, int i, long long  sum) {
    if (i > (n/2)-1) return;
    if (i == (n/2)-1) {
        if (res < sum) {
            res = sum;
        }
        return;
    }
    long long sum1 = sum;
    long long sum2 = sum;
    if (op[i+1] == '+') {
        sum1 += arr[i+2];
        sum2 += arr2[i+2];
    } else if (op[i+1] == '-') {
        sum1 -= arr[i+2];
        sum2 -= arr2[i+2];
    } else if (op[i+1] == '*') {
        sum1 *= arr[i+2];
        sum2 *= arr2[i+2];
    }
    dfs(arr, arr2, op, i+2, sum1);
    dfs2(arr, arr2, op, i+2, sum2);
}
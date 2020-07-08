#include <iostream>
#define endl    '\n'
using namespace std;
typedef long long ll;

int arr[1000001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b, c;
    cin >> n;
    for (int i  = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> b >> c;
    ll cnt = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] > b) {
            arr[i] -= b;
            cnt += arr[i] /c;
            cnt += arr[i] % c ? 1 : 0;
        }
    }

    printf("%lld", cnt);
    
    return 0;
}
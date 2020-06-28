#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, M, MAX = 0;
    cin >> n >> M;
    int sum = M;
    MAX = M;
    for(int i = 1; i < n; i++){
        int K;
        cin >> K;
        sum = max(sum+K, K);
        MAX = max(sum, MAX);
    }
    cout << MAX;

    return 0;
}

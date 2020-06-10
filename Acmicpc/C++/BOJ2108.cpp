#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[8001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
        arr[v[i]+4000]++;
    }

    // 1. 산술평균
    cout << round((float)sum / (float)N) << "\n";

    // 2. 중앙값
    sort(v.begin(), v.end());
    cout << v[N/2] << "\n";

    // 3. 최빈값
    int max_ = 0;
    int max_arr = 0;
    for (int i = 0; i < 8001; i++){
        max_ = max_ < arr[i] ? arr[i] : max_;
    }
    int cnt = 0;
    for (int i = 0; i < 8001; i++) {
        if (max_ == arr[i]) {
            max_arr = i;
            cnt ++;
        }
        if (cnt == 2) {
            break;
        }
    }
    cout << (max_arr - 4000) << "\n";

    // 4. 범위
    cout << (v[N-1] - v[0]) << "\n";

    return 0;
}
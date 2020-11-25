#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll low = 0, high = (ll)n * times.back(), answer = high;
    while (low <= high) {
        ll mid = (low + high) / 2, sum = 0;
        for (ll i : times) sum += mid / i;
        if (sum >= n) {
            answer = min(answer, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Answer;
ll arr[5001];
ll sum_(ll n) {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n%i==0) {
            ans += i;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int T, test_case;
	for (int i = 1; i <= 5000; i++) {
	    arr[i] = sum_(i);
	}
	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {
        int n1, n2;
        cin >> n1 >> n2;
        Answer = 0;
        for (int i = n1; i <= n2; i++) {
            Answer += arr[i];
        }
		
	    cout << "Case #" << test_case + 1 << "\n" << Answer << "\n";
	}

	return 0;
}
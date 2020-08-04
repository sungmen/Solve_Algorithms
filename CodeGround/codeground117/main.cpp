#include <bits/stdc++.h>
#include <string>
using namespace std;
int Answer;
int gcd(int a, int b) {
    if (b==0)
        return a;
    return gcd(b, a%b);
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		Answer = 0;
		string s1, m, equal;
        int n1 = 0, n2, m2;
        cin >> s1 >> m >> n2 >> equal >> m2;
        string::size_type sz;
        n1 = atoi(s1.c_str());
        m2 += n2;
        int l = gcd(n1, m2);
		cout << "Case #" << test_case+1 << endl;
		cout << (m2/l) << " / " << (n1/l) << endl;
	}

	return 0;
}
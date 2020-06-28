// BOJ9095.cpp
#include <iostream>
using namespace std;

int count;

void adding(int N) {
	if (N == 0) {
		::count+=1;
	}
	if (N > 0) {
		adding(N - 1);
		adding(N - 2);
		adding(N - 3);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		::count = 0;
		adding(N);
		cout << ::count << endl;
	}
	return 0;
}

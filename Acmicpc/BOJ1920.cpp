#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, bool> ma;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int n_test;
		scanf("%d", &n_test);
		ma.insert(pair<int, bool>(n_test, true));
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int m_test;
		scanf("%d", &m_test);
		printf("%d\n", ma.find(m_test)->second);
	}
}

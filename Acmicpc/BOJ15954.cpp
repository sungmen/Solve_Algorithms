#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n,&k);
	vector<int> v(n);
	double min = 999999999;
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for(int i = 0; i < n - k + 1; i++) {
		for(int m = k; m < n - i + 1; m++) {
			int sum = 0;
			for(int j = i; j < m + i; j++) {
				sum += v[j];
			}
			double ave = (double)sum/(double)m;
			double dis = 0.0;
			for(int j = i; j < m + i; j++) {
				dis += (v[j]-ave)*(v[j]-ave);
			}
			dis = sqrt(dis/(double)m);
			min = min > dis ? dis : min;
		}
	}
	printf("%.11lf\n", min);
	return 0;
}

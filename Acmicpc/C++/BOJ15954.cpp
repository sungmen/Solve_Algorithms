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
	for(int i = 0; i <= n - k; i++) {
		for(int m = k; m <= n - i; m++) {
			double sum = 0;
			for(int j = i; j < m + i; j++) {
				sum += v[j];
			}
			double ave = (double)sum/(double)m;
			sum = 0.0;
			for(int j = i; j < m + i; j++) {
				sum += (v[j]-ave)*(v[j]-ave);
			}
			sum = sqrt(sum/(double)m);
			min = min > sum ? sum : min;
		}
	}
	printf("%.11lf\n", min);
    return 0;
}

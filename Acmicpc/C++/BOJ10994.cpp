#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<char> > vc (4*N-3, vector<char> (4*N-3, ' '));
	int x, y, x_, y_;
	for(int i=0; i < N; i++) {
		if(i == 0) {
			x = (4*N-3)/2; y = (4*N-3)/2;
      x_ = x, y_ = y;
			vc[x][y] = '*';
		} else {
			x = x_ - (2 * i); y = y_ - (2 * i);
			for (int j = x; j <= x_ + (2*i); j++) {
				if(j == x || j == x_ + (2*i)) {
					for(int z = y; z <= x_ + (2*i); z++) {
						vc[j][z] = '*';
					}
				}else {
					vc[j][y] = vc[j][y_+(2*i)] = '*';
				}
			}
		}
	}
	for(int i = 0; i< 4*N-3; i++) {
		for(int j = 0; j < 4*N-3; j++) {
			printf("%c",vc[i][j]);
		}
		printf("\n");
	}

	return 0;
}

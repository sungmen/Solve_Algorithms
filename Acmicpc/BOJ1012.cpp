#include <cstdio>
#include <vector>

int dx[4] = {-1, 0, 1, 0}, 
    dy[4] = {0, 1, 0, -1}, 
    N, 
    M;

std::vector<std::vector<int> > arr;

void DFS(int X, int Y)  {
	for (int i = 0; i < 4; i++){
		int nextX = X + dx[i], nextY = Y + dy[i];
		if ((nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) || (arr[nextX][nextY] == 0))
			continue;
		arr[nextX][nextY] = 0;
		DFS(nextX, nextY);
	}
}

int main() {
	int T;
	scanf("%d",&T);

	for (int Testcase = 0; Testcase < T; Testcase++) {
    int count = 0, K;
		scanf("%d%d%d", &N, &M, &K);
    arr.assign(N, std::vector<int>(M,0));
		
    for(int i = 0; i < K; i++) {
      int n1, n2;
			scanf("%d%d", &n1, &n2);
			arr[n1][n2]=1;
		}

		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if(arr[i][j] != 0) {
					DFS(i, j);
				  count++;
        }

    printf("%d\n", count);
	}

	return 0;
}

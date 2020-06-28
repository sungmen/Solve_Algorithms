#include <stdio.h>

int arr[101] = {0};
int map[101][101] = {0};
int com, cnt;

void dfs (int n) {
    cnt++;
    arr[n] = 1;
    for(int i = 1; i <= com; i++)
        if(map[n][i] && !arr[i]) dfs(i);
}

int main() {
    int pairs;
    scanf("%d%d", &com, &pairs);
    for(int t = 0; t < pairs; t++) {
        int n, m;
        scanf("%d%d",&n,&m);
        map[n][m] = map[m][n] = 1;
    }
    
    dfs(1);
    
    printf("%d", --cnt);

    return 0;
}
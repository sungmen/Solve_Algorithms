#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int arr[101][101];
int path[101][101];
int cnt = 2;
void printPath(int start, int end) {
    if (path[start-1][end - 1] != -1) {
        printPath(start, path[start - 1][end - 1]);
        cnt++;
        printPath(path[start - 1][end - 1], end);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, R;
    cin >> N;
    for(int i = 1; i <= N; i++) for (int j = 1; j <= N; j++){ arr[i][j] = INF; path[i][j]=-1;}
    for(int i = 1; i <= N; i++) arr[i][i] = 0;
    for (cin >> R; R--;){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if(e>10) {
            e-=10;
            if(arr[a][b] > c + d*e) {
                arr[a][b] = c + d*e;
            }
        } else {
            if (arr[a][b] > c) {
                arr[a][b] = c;
            }
        }
    }
    for (int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if (arr[i][k] + arr[k][j] < arr[i][j]){ path[i][j] = k+1; arr[i][j] = arr[i][k] + arr[k][j];}
    if(arr[1][N] != INF && arr[1][N] != 0) {
        int start = 2, end = N+1;
        printPath(start, end);
        cout << arr[1][N] << ' ' << cnt;
    } else {
        cout << "It is not a great way.";
    }
    return 0;
}

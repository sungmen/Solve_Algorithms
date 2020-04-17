#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> v(n, vector<int>(3));
    vector<vector<int>> d(n, vector<int>(3));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++){
            scanf("%d", &v[i][j]);
            if(i == 0)
                d[0][j] = v[0][j];
        }

    for (int i = 1; i < n; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + v[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + v[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + v[i][2];
    }

    int MIN = d[n-1][0];
    for(int i = 0; i < 3; i++) {
        if (d[n-1][i] < MIN)
            MIN = d[n-1][i];
    }

    printf("%d\n", MIN);
    return 0;
}

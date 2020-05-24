#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char arW[8][8] = {{'W','B','W','B','W','B','W','B'},
                 {'B','W','B','W','B','W','B','W'},
                 {'W','B','W','B','W','B','W','B'},
                 {'B','W','B','W','B','W','B','W'},
                 {'W','B','W','B','W','B','W','B'},
                 {'B','W','B','W','B','W','B','W'},
                 {'W','B','W','B','W','B','W','B'},
                 {'B','W','B','W','B','W','B','W'}};
char arB[8][8] = {{'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector <vector<char> >v(N, vector<char>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    int MIN = INT32_MAX;
    int cnt = 0;
    int nf = N - 8, mf = M - 8;
    for(int i = 0; i <= nf; i++) {
        for (int j = 0; j <= mf; j++) { 
            cnt = 0;
            for(int a = 0; a < 8; a++) {
                for(int b= 0; b < 8; b++) {
                    if(v[i+a][j+b] != arW[a][b])
                        cnt++;
                }
            }
            MIN = min(MIN, cnt);
            cnt = 0;
            for(int a = 0; a < 8; a++) {
                for(int b= 0; b < 8; b++) {
                    if(v[i+a][j+b] != arB[a][b])
                        cnt++;
                }
            }
            MIN = min(cnt, MIN);
        }
    }
    cout << MIN;
    return 0;
}
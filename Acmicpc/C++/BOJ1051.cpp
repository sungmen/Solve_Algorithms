#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> vi(n, vector<int>(m));
    char chr[50];
    for(int i = 0; i < n; i++){
        scanf("%s", &chr);
        for(int j = 0; j < m; j++) {
            vi[i][j] = (int)(chr[j] - '0');
        }
    }
    
    int min = n > m ? m : n;
    int result = 1;
    for(int num = 1; num < min; num++) {
        for(int i = 0; i < n - num; i++) {
            for(int j = 0; j < m - num; j++) {
                if(vi[i][j] == vi[i][j+num] && vi[i][j]==vi[i+num][j] && vi[i][j] == vi[i+num][j+num])
                    result = (num + 1) * (num + 1);
            }
        }
    }

    printf("%d", result);


    return 0;
}
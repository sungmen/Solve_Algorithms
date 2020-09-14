#include <string>
#include <vector>
using namespace std;
int arr[1000][1000];
vector<int> solution(int n) {
    vector<int> answer;
    int p = n;
    int k = 1;
    int x = -1, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = p;j >= 1; j--) {
            if(i%3==0) {
                arr[++x][y] = k;
            } else if (i % 3 == 1) {
                arr[x][++y] = k;
            } else if (i % 3 == 2) {
                arr[--x][--y] = k;
            }
            k++;
        }
        p--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i;  j++) {
            answer.emplace_back(arr[i][j]);
        }
    }
    
    return answer;
}
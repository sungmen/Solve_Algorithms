// https://www.acmicpc.net/problem/2740
#include <stdio.h>
#include <vector>

int main() {
    // 첫 번째 행렬
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int> > arr1(n, std::vector<int>(m));  
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    int n2, m2;
    // 두 번째 행렬
    scanf("%d%d", &n2, &m2);
    std::vector<std::vector<int> > arr2(n2, std::vector<int>(m2));
    for(int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // 행렬 곱
    std::vector<std::vector<int> > arr3(n, std::vector<int>(m2, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m2; j++) {
            for(int k = 0; k < m; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d " , arr3[i][j]);
        }
        printf("\n");
    }


    return 0;
}
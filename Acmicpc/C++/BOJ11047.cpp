// BOJ11047.cpp

#include <iostream>

int CNT(int* M, int N, int K) {
    int count = 0;
    for (int i = N-1; i >= 0 ; i--) {
        if (K >= M[i]) {
            count += (K/M[i]);
            K %= M[i];
        }
    }
    return count;
}

int main() {
    std::cin.tie(0);
    int N, K;
    std::cin >> N >> K;
    
    int* M = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> M[i];
    
    std::cout << CNT(M, N, K) << std::endl;
    delete M;

    return 0;
}
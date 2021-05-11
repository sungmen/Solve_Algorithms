#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int start = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = start; j < B.size(); j++) {
            if (A[i] < B[j]) {
                ++answer;
                start = ++j;
                break;
            }
        }
    }
    return answer;
}
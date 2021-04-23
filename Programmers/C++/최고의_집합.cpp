#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s / n == 0) return {-1};
    while (n != 0) {
        answer.push_back(s / n);
        s -= s/n;
        n--;
    }
    sort(answer.begin(), answer.end());
    return answer;
}
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int tmp = routes[0][1];
    for (int i = 0; i < routes.size(); i++) {
        if (routes[i][0] > tmp) {
            tmp = routes[i][1];
            ++answer;
        }
        else if (routes[i][1] <= tmp) {
            tmp = routes[i][1];
        }
    }
    return answer;
}
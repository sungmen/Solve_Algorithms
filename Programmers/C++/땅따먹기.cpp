#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int> > land) {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i < land.size(); i++) {
        land[i][0] += max(land[i-1][1], max(land[i-1][2], land[i-1][3]));
        land[i][1] += max(land[i-1][0], max(land[i-1][2], land[i-1][3]));
        land[i][2] += max(land[i-1][0], max(land[i-1][1], land[i-1][3]));
        land[i][3] += max(land[i-1][1], max(land[i-1][2], land[i-1][0]));
    }
    return max(max(land[land.size()-1][0], land[land.size()-1][1]), max(land[land.size()-1][2], land[land.size()-1][3]));
}
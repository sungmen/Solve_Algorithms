#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> vi(N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &vi[i].first, &vi[i].second);
    }
    sort(vi.begin(), vi.end(), compare);

    for(auto i : vi) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
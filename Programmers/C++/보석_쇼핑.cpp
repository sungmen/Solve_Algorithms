#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 100001};
    map<string, int> m;
    for (auto s : gems) {
        if (!m[s]) m[s] = 1;
    }
    int mSize = m.size();
    int l = 0, r = 0;
    map<string, int> ms;
    while (r < gems.size()) {
        ms[gems[r]]++;
        if (ms[gems[r]] > 1 && gems[l] == gems[r]) {
            l++;
            ms[gems[r]]--;
        }
        while(1) {
            if (ms[gems[l]] > 1) {
                string str = gems[l];
                while (ms[str] > 1) {
                    ms[gems[l]]--;
                    l++;
                    if (str != gems[l]) break;
                }
            } else {
                break;
            }
        }
        if (ms.size() == mSize) {
            int diff = answer[1]-answer[0];
            if (diff > r-l) {
                answer = {l, r};
            }
        }
        r++;
    }
    return {answer[0]+1,answer[1]+1};
}
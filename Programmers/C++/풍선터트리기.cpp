#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a) {
    int answer = 2;
    vector<int> l(a.size(), 0), r(a.size(), 0);
    l[0] = a[0];
    for (int i = 1; i < a.size(); l[i] = min(a[i], l[i-1]), i++);
    r[a.size()-1] = a[a.size()-1];
    for (int i = a.size()-2; i >= 0; r[i] = min(a[i], r[i+1]), i--);
    for (int i = 1; i < a.size()-1; i++) if (a[i] < max(l[i-1], r[i+1])) answer += 1;
    return answer;
}
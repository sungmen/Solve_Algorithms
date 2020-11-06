#include <bits/stdc++.h>
using namespace std;
pair<int, int> sort(map<int, int> &m) {
    multimap<int, int> mm;
    for(auto& it: m) mm.insert({it.second, it.first});
    return {(--mm.end())->second, (--mm.end())->first};
}
int solution(std::vector<int> a) {
    int answer = 0;
    map<int, int> m;
    for(int i = 0; i < a.size(); i++) {
        if(m.find(a[i]) == m.end()) m[a[i]] = 1;
        else m[a[i]]++;
    }
    pair<int,int> tmp = sort(m);
    cout << tmp.first << ' ' << tmp.second<<'\n';
    int tmp2 = -1;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != tmp.first) {
            if(tmp2 == -1) tmp2 = a[i];
            else {
                if(tmp2 == tmp.first) {
                    answer++;
                    tmp2 = -1;
                } else {
                    continue;
                }
            }
        } else {
            if(tmp2 == -1) tmp2 = a[i];
            else {
                if(tmp2 == tmp.first) continue;
                else {
                    answer++;
                    tmp2 = -1;
                }
            }
        }
    }
    if(a.size() <= 1) return 0;
    return answer * 2;
}
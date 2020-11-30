// https://www.geeksforgeeks.org/lru-cache-implementation/
#include <bits/stdc++.h>
using namespace std;
int answer = 0;

string tolower(string s) {
    transform(s.begin(), s.end(), s.begin(), (int(*)(int))tolower);
    return s;
}

struct comp {
    bool operator() (const string& lh, const string& rh) const {
        return tolower(lh) < tolower(rh);
    }
};

class LRUc {
    list<string> li;
    map<string, list<string>::iterator, comp> um;
    int size_c;
public:
    LRUc(int);
    void refer(string);
};
LRUc::LRUc(int n) {
    size_c = n;
}
void LRUc::refer(string x) {
    if(um.find(x) == um.end()) {
        answer += 5;
        if(li.size() == size_c) {
            string last = li.back();
            li.pop_back();
            um.erase(last);
        }
    } else {
        answer++;
        li.erase(um[x]);
    }
    li.push_front(x);
    um[x] = li.begin();
}
int solution(int cacheSize, vector<string> cities) {
    if (!cacheSize) answer = cities.size() * 5;
    else {
        LRUc lru(cacheSize);
        for (auto i : cities) {
            lru.refer(i);
        }
    }
    return answer;
}
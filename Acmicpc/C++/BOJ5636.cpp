#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define vs vector<string>
const int MAX = 1e6 + 1;
bool chkPrim[MAX];
map<string, int> prim;

vs inputval() {
    vs str;
    while (1) {
        string s; cin >> s;
        if (s == "0") break;
        str.push_back(s);
    }
    return str;
}

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << '\n';
    }
}

void calprime() {
    memset(chkPrim, 1, sizeof(chkPrim));
    for (int i = 2; i < MAX; ++i) {
        if (chkPrim[i]) {
            prim[to_string(i)] = 1;
            for (int j = i + i; j < MAX; j += i) {
                chkPrim[j] = false;
            }
        }
    }
}

vector<int> sol(vs str) {
    calprime();
    vector<int> res;
    for (int i = 0; i < str.size(); ++i) {
        int ans = 0;
        for (int j = 0; j < str[i].size(); ++j) {
            for (int k = 0; k < 6 && j + k < str[i].size(); ++k) {
                if(prim[str[i].substr(j, k)]) {
                    ans = max(ans, stoi(str[i].substr(j, k)));
                }
            }
        }
        res.push_back(ans);
    }
    return res;
}

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    print(sol(inputval()));
    return 0;
}
